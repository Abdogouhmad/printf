


int _printf(const char *format, ...)
{
	int count = 0;
	va_list myarg;
	va_start(myarg, format);
	int i, str_length, count_char = 0;

	for (i = 0; format[i] != '\0'; i++) {

		if (format[i] != '%') {
			write(1, &format[i], 1);
			count_char++;

		} else {
			i++;

			if (format[i] == 'd' || format[i] == 'i')
			{
				int num = va_arg(myarg, int);

				num_to_string(num, &count_char);
			}
		}
	}

	va_end(myarg);
	return count_char;
}










// this main function is for stress testing my code

int main()
{
	int count = 0;

	// basic test cases
	count = _printf("Hello, world!\n");
	printf("Number of characters printed: %d\n\n", count);

	count = _printf("The first five even numbers are: %d %d %d %d %d\n", 2, 4, 6, 8, 10);
	printf("Number of characters printed: %d\n\n", count);

	count = _printf("The square root of 2 is approximately %f\n", 1.41421356);
	printf("Number of characters printed: %d\n\n", count);

	// stress test case: print 10000 numbers
	printf("Printing 10000 numbers:\n");
	for (int i = 0; i < 10000; i++) {
		count = _printf("%d ", i);
	}
	printf("\nNumber of characters printed: %d\n\n", count);

	// stress test case: print a large number
	int large_num = 1234567890;
	count = _printf("Large number: %d\n", large_num);
	printf("Number of characters printed: %d\n\n", count);

	count = _printf("Hello, world!\n");
	printf("Number of characters printed: %d\n\n", count);

	count = _printf("The first five even numbers are: %d %d %d %d %d\n", 2, 4, 6, 8, 10);
	printf("Number of characters printed: %d\n\n", count);

	count = _printf("The square root of 2 is approximately %f\n", 1.41421356);
	printf("Number of characters printed: %d\n\n", count);

	count = _printf("This is a very long string that should test whether our printf function can handle very long strings without any issues. I really hope it can, because otherwise we might be in trouble!\n");
	printf("Number of characters printed: %d\n\n", count);

	count = _printf("%d\n", 1234567890);
	printf("Number of characters printed: %d\n\n", count);

	count = _printf("%d\n", -1234567890);
	printf("Number of characters printed: %d\n\n", count);


	return 0;
}