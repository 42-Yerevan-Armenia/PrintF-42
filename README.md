# PrintF-42

Մենք ունենք string որում առկա է % և format specifiers(`fs`)-ներից մեկը(16 կամ ավել): Եթե չկա մեր string-ը՝ (null): Ամեն մի `fs` ունի իր կիրառման flag-ը և յուրահատուկ է յուրովին՝
We have a string containing one of the % և format specifiers (`fs`) (16 or higher).
Each `fs` has its own application flag and is unique itself.
- %c Prints a single character. 
- %s Prints a string (as defined by the common C convention). 
- %p Print the void * pointer argument in hexadecimal format. 
- %d Prints a decimal (base 10) number.
- %i Prints an integer in base 10. (%d and %i pretty the same)
- %u Prints an unsigned decimal (base 10) number. 
- %x Prints a number in hexadecimal (base 16) lowercase format. 
- %X Prints a number in hexadecimal (base 16) uppercase format. 
- %% Prints a percent sign.

Variable Argument. Ինչպես երևում է մեր prototype-ից int ft_printf(const char *s, ...) մենք ունենք ինչ-որ “...”-ր: Սա նշանակում է, որ մենք չգիտենք թե քանի parametr ունենք և այն կորող է ընդունել այնքան, որքան մեզ կարող է տրամադրել մեր հիշողությունը: Այսպիսով մենք կօգտագործենք՝

```
va_list	-	list, որը հավաքում և պահում է մեր բոլոր parameter-րը “...”-ում
va_arg	-	մտնում է մեր list և վերցնում այն parameter-ը, որը պետք է տվյալ flag-ին
va_start	-	ֆունկցիայում այն տեղը, որտեղից սկսած կօգտագործվեն մեր list-ը
va_end	-	list-րի օգտագործման վերջը
… -> int, char *, unsigned long long, int, unsigned int, unsigned int
… -> va_list ap
va_arg(ap, int) -> go to ap(va_list) and take from there parameter with int, then go next
va_arg(ap, char *)
va_arg(ap, unsigned long long)
va_arg(ap, int)
va_arg(ap, unsigned int)
va_arg(ap, unsigned int)
```

<p>%p -> հասցեները 16 ական համակարգով են, նույնականացվում են “0x”-ով, գրվում են փոքրատառերով (in Ascii decimal(10) -> 97 / hexadecimal(16) -> 87)

<p>%xX Վերադարձնուում է տրված թիվը վերափոխված (convert) 16-ական /hexadecimal/ համակարգի, մեծատառ(x) կամ փոքրատառ (X)
<p>convert անելու համար, թիվը բաժանում ենք մեր ուզած համակարգին (տվյալ դեպքում՝ 16-ի), ստցված մնացորդը, որը գրում ենք հակառակ հերթականությամբ: 

<p>հուշում այն մասին, թե ինչպես կարելի է գրել ֆոուունկցիա՝ թվի convert-ի համար
- 456	% 16 = 5
= 28	% 16 = 7	570 -> reversed to 075
= 1	% 16 = 0
