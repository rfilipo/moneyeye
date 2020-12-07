#define PERL_constant_NOTFOUND	1
#define PERL_constant_NOTDEF	2
#define PERL_constant_ISIV	3
#define PERL_constant_ISNO	4
#define PERL_constant_ISNV	5
#define PERL_constant_ISPV	6
#define PERL_constant_ISPVN	7
#define PERL_constant_ISSV	8
#define PERL_constant_ISUNDEF	9
#define PERL_constant_ISUV	10
#define PERL_constant_ISYES	11

#ifndef NVTYPE
typedef double NV; /* 5.6 and later define NVTYPE, and typedef NV to it.  */
#endif
#ifndef aTHX_
#define aTHX_ /* 5.6 or later define this for threading support.  */
#endif
#ifndef pTHX_
#define pTHX_ /* 5.6 or later define this for threading support.  */
#endif

static int
constant (pTHX_ const char *name, STRLEN len, IV *iv_return) {
  /* Initially switch on the length of the name.  */
  /* When generated this function returned values for the list of names given
     in this section of perl code.  Rather than manually editing these functions
     to add or remove constants, which would result in this comment and section
     of code becoming inaccurate, we recommend that you edit this section of
     code, and use it to regenerate a new set of constant functions which you
     then use to replace the originals.

     Regenerate these constant functions by feeding this entire source file to
     perl -x

#!/usr/bin/perl -w
use ExtUtils::Constant qw (constant_types C_constant XS_constant);

my $types = {map {($_, 1)} qw(IV)};
my @names = (qw(),
            {name=>"Administrator", type=>"IV", macro=>"1"},
            {name=>"Analyse", type=>"IV", macro=>"1"},
            {name=>"Buy", type=>"IV", macro=>"1"},
            {name=>"Credit", type=>"IV", macro=>"1"},
            {name=>"Debit", type=>"IV", macro=>"1"},
            {name=>"Guest", type=>"IV", macro=>"1"},
            {name=>"Sell", type=>"IV", macro=>"1"},
            {name=>"Trader", type=>"IV", macro=>"1"},
            {name=>"User", type=>"IV", macro=>"1"});

print constant_types(), "\n"; # macro defs
foreach (C_constant ("Money::Eye", 'constant', 'IV', $types, undef, 3, @names) ) {
    print $_, "\n"; # C constant subs
}
print "\n#### XS Section:\n";
print XS_constant ("Money::Eye", $types);
__END__
   */

  switch (len) {
  case 3:
    if (memEQ(name, "Buy", 3)) {
      *iv_return = Buy;
      return PERL_constant_ISIV;
    }
    break;
  case 4:
    /* Names all of length 4.  */
    /* Sell User */
    /* Offset 0 gives the best switch position.  */
    switch (*name++) {
    case 'S':
      if (memEQ(name, "ell", 3)) {
      /*                S         */
        *iv_return = Sell;
        return PERL_constant_ISIV;
      }
      break;
    case 'U':
      if (memEQ(name, "ser", 3)) {
      /*                U         */
        *iv_return = User;
        return PERL_constant_ISIV;
      }
      break;
    }
    break;
  case 5:
    /* Names all of length 5.  */
    /* Debit Guest */
    /* Offset 0 gives the best switch position.  */
    switch (*name++) {
    case 'D':
      if (memEQ(name, "ebit", 4)) {
      /*                D          */
        *iv_return = Debit;
        return PERL_constant_ISIV;
      }
      break;
    case 'G':
      if (memEQ(name, "uest", 4)) {
      /*                G          */
        *iv_return = Guest;
        return PERL_constant_ISIV;
      }
      break;
    }
    break;
  case 6:
    /* Names all of length 6.  */
    /* Credit Trader */
    /* Offset 5 gives the best switch position.  */
    switch (name[5]) {
    case 'r':
      if (memEQ(name, "Trade", 5)) {
      /*                    r     */
        *iv_return = Trader;
        return PERL_constant_ISIV;
      }
      break;
    case 't':
      if (memEQ(name, "Credi", 5)) {
      /*                    t     */
        *iv_return = Credit;
        return PERL_constant_ISIV;
      }
      break;
    }
    break;
  case 7:
    if (memEQ(name, "Analyse", 7)) {
      *iv_return = Analyse;
      return PERL_constant_ISIV;
    }
    break;
  case 13:
    if (memEQ(name, "Administrator", 13)) {
      *iv_return = Administrator;
      return PERL_constant_ISIV;
    }
    break;
  }
  return PERL_constant_NOTFOUND;
}

