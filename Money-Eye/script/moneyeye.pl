#!/usr/bin/perl
# Simple Curses::UI MoneyEye Calculator
# Author: Monsenhor

use warnings;
use strict;
use Carp;
use File::Temp qw( :POSIX );
use lib ("../lib", "./lib");
#use ExtUtils::testlib;
#use Money::Eye;

#Money::Eyey::deposit(8000);

#   make KEY_BTAB (shift-tab) working in XTerm
#   and also at the same time enable colors
$ENV{TERM} = "xterm-vt220" if ( $ENV{TERM} eq 'xterm' );

my $debug = 0;
if ( @ARGV and $ARGV[0] eq '-d' ) {
    my $fh = tmpfile();
    open STDERR, ">", $fh or croak "Can't open '$fh': $!"; 
    $debug = 1;
}
else {
    # We do not want STDERR to clutter our screen.
    my $fh = tmpfile();
    open STDERR, ">", $fh or croak "Can't open '$fh': $!"; 
}

use FindBin;
use lib "$FindBin::RealBin/../lib";
use Curses::UI;

################################################
# model structure
################################################

my $current_state = 0;  # the focused screen
my %w = ();             # the screens
my $userdata      = {}; # the data in some screens for callbacks


###################################################
# UI - view structure
###################################################

# Create the root object.
my $cui = new Curses::UI(
    -color_support => 1,
    -clear_on_exit => 1,
    -debug         => $debug,
);

# ----------------------------------------------------------------------
# menu bar
# ----------------------------------------------------------------------

my $file_menu = [
    {
        -label => 'list articles',
        -value => sub { list_articles() }
    },
    {
        -label => 'edit article',
        -value => sub {
            #if ($selected_article) {
            #    get_article();
            #}
            #else {
                list_articles();
            #}
        }
    },
		{
        -label => 'main page',
        -value => sub { select_state(1); }
    },
		{
        -label => 'server control',
        -value => sub { select_state(6); }
    },
    {
        -label => 'quit program',
        -value => sub { exit(0) }
    },
];

my $menu = [
    { -label => 'file', -submenu => $file_menu },
];

$cui->add(
    'menu', 'Menubar',
    -menu => $menu,

    -bg => "blue",
    -fg => "black",
);

# ----------------------------------------------------------------------
# message bar
# ----------------------------------------------------------------------

my $w0 = $cui->add(
    'w0', 'Window',
    -border => 1,
    -y      => -1,
    -height => 3,
    -bg     => "blue",
    -fg     => "black",
    -bfg    => "blue",
);
$w0->add( 'explain', 'Label',
    -text => "CTRL+A: list articles  CTRL+E: edit article  "
      . "CTRL+X: menu  CTRL+Q: quit" );

# ----------------------------------------------------------------------
# the screens
# ----------------------------------------------------------------------

my %screens = (
    '1' => 'home',
    '2' => 'list articles',
    '3' => 'list users',
    '4' => 'article editor',
    '5' => 'user editor',
    '6' => 'app control',
);

my @screens = sort { $a <=> $b } keys %screens;

my %args = (
    -border       => 0,
    -titlereverse => 1,
    -padtop       => 2,
    -padbottom    => 3,
    -ipad         => 0,
    -tbg          => "blue",
    -tfg          => "black",
    -bfg          => "blue",
);

while ( my ( $nr, $title ) = each %screens ) {
    my $id = "window_$nr";
    $w{$nr} = $cui->add(
        $id, 'Window',

        #-title => "Mojo::App admin: $title ($nr/" . @screens . ")",
        -titlefullwidth => 1,
        -title          => ": $title",
        %args
    );
}


$cui->mainloop;

__END__


# Home App
my $current_state = 0;
my $selected_article;

# App windows
my %w = ();

# ----------------------------------------------------------------------
# main menu
# ----------------------------------------------------------------------

sub select_state() {
    my $nr = shift;
    $current_state = $nr;
    $w{$current_state}->focus;
}

my $file_menu = [
    {
        -label => 'list articles',
        -value => sub { list_articles() }
    },
    {
        -label => 'edit article',
        -value => sub {
            if ($selected_article) {
                get_article();
            }
            else {
                list_articles();
            }
        }
    },

    #    {
    #        -label => 'new article',
    #        -value => sub { select_state(4) }
    #    },
    #    {
    #        -label => '------------',
    #        -value => sub { }
    #    },
    #    {
    #        -label => 'users',
    #        -value => sub { select_state(10) }
    #    },
    {
        -label => 'quit program',
        -value => sub { exit(0) }
    },
  ],

  my $menus_menu = [
    {
        -label => 'list menus',
        -value => sub { select_state(5) }
    },
    {
        -label => 'new menu',
        -value => sub { select_state(6) }
    },
  ];

my $users_menu = [
    {
        -label => 'list users',
        -value => sub { select_state(7) }
    },
    {
        -label => 'user profile',
        -value => sub { select_state(8) }
    },
    {
        -label => 'new user',
        -value => sub { select_state(9) }
    },
];
my $menu = [
    { -label => 'file', -submenu => $file_menu },

    #    { -label => 'menus', -submenu => $menus_menu },
    #    { -label => 'users', -submenu => $users_menu },
];

$cui->add(
    'menu', 'Menubar',
    -menu => $menu,

    -bg => "blue",
    -fg => "black",
);

# ----------------------------------------------------------------------
# Create the explanation window
# ----------------------------------------------------------------------

my $w0 = $cui->add(
    'w0', 'Window',
    -border => 1,
    -y      => -1,
    -height => 3,
    -bg     => "blue",
    -fg     => "black",
    -bfg    => "blue",
);
$w0->add( 'explain', 'Label',
    -text => "CTRL+A: list articles  CTRL+E: edit article  "
      . "CTRL+X: menu  CTRL+Q: quit" );

# ----------------------------------------------------------------------
# the app state windows
# ----------------------------------------------------------------------

my %screens = (
    '1' => 'home',
    '2' => 'list articles',
    '3' => 'list users',
    '4' => 'article editor',
    '5' => 'user editor',
    '6' => 'app control',
);

my @screens = sort { $a <=> $b } keys %screens;

my %args = (
    -border       => 0,
    -titlereverse => 1,
    -padtop       => 2,
    -padbottom    => 3,
    -ipad         => 0,
    -tbg          => "blue",
    -tfg          => "black",
    -bfg          => "blue",
);

while ( my ( $nr, $title ) = each %screens ) {
    my $id = "window_$nr";
    $w{$nr} = $cui->add(
        $id, 'Window',

        #-title => "Mojo::App admin: $title ($nr/" . @screens . ")",
        -titlefullwidth => 1,
        -title          => ": $title",
        %args
    );
}


