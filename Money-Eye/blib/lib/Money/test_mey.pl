#!/usr/bin/perl -w

use strict;
use warnings;
use 5.10.0;

use lib ".", "./blib/lib","blib/arch/auto/Money/Eye/";

use Money::Eye ":all";
use Carp;
use Data::Dumper;

my $st = stock::new({name => "test", value => 5.67, owned => 0});
print Dumper $st;
my $sp = stock::_to_ptr($st);
print Dumper $sp;
my $me = Money::Eye::trader($sp,0.456,68);
print Dumper $me; 
#my $test = Money::Eye::user::new();
#print "look at test:\n";
#print Dumper $test;


my $fail = 0;
foreach my $constname (qw(
	Administrator Analyse Buy Credit Debit Guest Sell Trader User)) {
  print (eval $constname);
  print " - $constname \n";
  next if (eval "my \$a = $constname; 1");
  if ($@ =~ /^Your vendor has not defined Money::Eye macro $constname/) {
    print "# pass: $@";
  } else {
    print "# fail: $@";
    $fail = 1;
  }

}


