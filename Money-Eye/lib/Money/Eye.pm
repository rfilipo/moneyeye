package Money::Eye;

use 5.010000;
use strict;
use warnings;
use Carp;

require Exporter;
use AutoLoader;

our @ISA = qw(Exporter);

# Items to export into callers namespace by default. Note: do not export
# names by default without a very good reason. Use EXPORT_OK instead.
# Do not simply export all your public functions/methods/constants.

# This allows declaration	use Money::Eye ':all';
# If you do not need this, moving things directly into @EXPORT or @EXPORT_OK
# will save memory.
our %EXPORT_TAGS = ( 'all' => [ qw(
	Administrator
	Analyse
	Buy
	Credit
	Debit
	Guest
	Sell
	Trader
	User
	analyse
	balance
	debit
	deposit
	trader
) ] );

our @EXPORT_OK = ( @{ $EXPORT_TAGS{'all'} } );

our @EXPORT = qw(
	Administrator
	Analyse
	Buy
	Credit
	Debit
	Guest
	Sell
	Trader
	User
);

our $VERSION = '0.01';

sub AUTOLOAD {
    # This AUTOLOAD is used to 'autoload' constants from the constant()
    # XS function.

    my $constname;
    our $AUTOLOAD;
    ($constname = $AUTOLOAD) =~ s/.*:://;
    croak "&Money::Eye::constant not defined" if $constname eq 'constant';
    my ($error, $val) = constant($constname);
    if ($error) { croak $error; }
    {
	no strict 'refs';
	# Fixed between 5.005_53 and 5.005_61
#XXX	if ($] >= 5.00561) {
#XXX	    *$AUTOLOAD = sub () { $val };
#XXX	}
#XXX	else {
	    *$AUTOLOAD = sub { $val };
#XXX	}
    }
    goto &$AUTOLOAD;
}

require XSLoader;
XSLoader::load('Money::Eye', $VERSION);

# Preloaded methods go here.

# Autoload methods go after =cut, and are processed by the autosplit program.

1;
__END__
# Below is stub documentation for your module. You'd better edit it!

=head1 NAME

Money::Eye - Perl extension for blah blah blah

=head1 SYNOPSIS

  use Money::Eye;
  blah blah blah

=head1 DESCRIPTION

Stub documentation for Money::Eye, created by h2xs. It looks like the
author of the extension was negligent enough to leave the stub
unedited.

Blah blah blah.

=head2 EXPORT

None by default.

=head2 Exportable constants

  Administrator
  Analyse
  Buy
  Credit
  Debit
  Guest
  Sell
  Trader
  User

=head2 Exportable functions

  int analyse (char *json)
  double balance (char *period)
  int debit (double value)
  int deposit (double value)
  int trader (stock *s, double value, enum operation m)


=head2 Object and class methods for C<trade>/C<tradePtr>

The principal Perl representation of a C object of type C<trade> is an
object of class C<tradePtr> which is a reference to an integer
representation of a C pointer.  To create such an object, one may use
a combination

  my $buffer = trade->new();
  my $obj = $buffer->_to_ptr();

This exercises the following two methods, and an additional class
C<trade>, the internal representation of which is a reference to a
packed string with the C structure.  Keep in mind that $buffer should
better survive longer than $obj.

=over

=item C<$object_of_type_trade-E<gt>_to_ptr()>

Converts an object of type C<trade> to an object of type C<tradePtr>.

=item C<trade-E<gt>new()>

Creates an empty object of type C<trade>.  The corresponding packed
string is zeroed out.

=item C<movement(...)>, C<description(...)>, C<asset(...)>, C<value(...)>

return the current value of the corresponding element if called
without additional arguments.  Set the element to the supplied value
(and return the new value) if called with an additional argument.

Applicable to objects of type C<tradePtr>.

=back


=head2 Object and class methods for C<user>/C<userPtr>

The principal Perl representation of a C object of type C<user> is an
object of class C<userPtr> which is a reference to an integer
representation of a C pointer.  To create such an object, one may use
a combination

  my $buffer = user->new();
  my $obj = $buffer->_to_ptr();

This exercises the following two methods, and an additional class
C<user>, the internal representation of which is a reference to a
packed string with the C structure.  Keep in mind that $buffer should
better survive longer than $obj.

=over

=item C<$object_of_type_user-E<gt>_to_ptr()>

Converts an object of type C<user> to an object of type C<userPtr>.

=item C<user-E<gt>new()>

Creates an empty object of type C<user>.  The corresponding packed
string is zeroed out.

=item C<name(...)>, C<status(...)>, C<cash(...)>, C<receivable(...)>, C<due(...)>

return the current value of the corresponding element if called
without additional arguments.  Set the element to the supplied value
(and return the new value) if called with an additional argument.

Applicable to objects of type C<userPtr>.

=back


=head2 Object and class methods for C<stock>/C<stockPtr>

The principal Perl representation of a C object of type C<stock> is an
object of class C<stockPtr> which is a reference to an integer
representation of a C pointer.  To create such an object, one may use
a combination

  my $buffer = stock->new();
  my $obj = $buffer->_to_ptr();

This exercises the following two methods, and an additional class
C<stock>, the internal representation of which is a reference to a
packed string with the C structure.  Keep in mind that $buffer should
better survive longer than $obj.

=over

=item C<$object_of_type_stock-E<gt>_to_ptr()>

Converts an object of type C<stock> to an object of type C<stockPtr>.

=item C<stock-E<gt>new()>

Creates an empty object of type C<stock>.  The corresponding packed
string is zeroed out.

=item C<name(...)>, C<value(...)>, C<owned(...)>

return the current value of the corresponding element if called
without additional arguments.  Set the element to the supplied value
(and return the new value) if called with an additional argument.

Applicable to objects of type C<stockPtr>.

=back



=head1 SEE ALSO

Mention other useful documentation such as the documentation of
related modules or operating system documentation (such as man pages
in UNIX), or any relevant external documentation such as RFCs or
standards.

If you have a mailing list set up for your module, mention it here.

If you have a web site set up for your module, mention it here.

=head1 AUTHOR

filipo, E<lt>filipo@E<gt>

=head1 COPYRIGHT AND LICENSE

Copyright (C) 2016 by filipo

This library is free software; you can redistribute it and/or modify
it under the same terms as Perl itself, either Perl version 5.22.1 or,
at your option, any later version of Perl 5 you may have available.


=cut
