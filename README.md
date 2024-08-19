# Base Converter

This program convert a number from any base to any other base.

To execute the program use the command `cv`. See examples below:

```sh
cv <Number><Old Base> <New Base>

cv 1111/2 10 # 1111 in base 2 equals 15 in base 10

cv 011111111/2 16 # The leading zero will be ignored
```

## Assumptions

This program assumes that the character encoding in `char` is [ASCII](https://en.wikipedia.org/wiki/ASCII) (which it should be). It my work on other encodings as will, but I haven't tested that. Please contact me, if you find it out.