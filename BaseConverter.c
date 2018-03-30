
#include <stdio.h>
#include <math.h>

void main(void)
{
	char base_digits[16] =
	{ '0', '1', '2', '3', '4', '5', '6', '7',
		'8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };

	int choice;
	do {
		int t, t2;
		int converted_number[64];
		int converted_base_10 = 0, temp;
		long int number_to_convert;
		int next_digit, base, index = 0;

		printf("Please choose program:\n          (0) Convert to base 10\n          (1) Convert from base 10\n          (-1) Quit\n");
		scanf("%d", &choice);
		switch (choice)
		{
			case 1:

				printf("Enter number in base 10 and desired base (2-16): ");
				scanf("%ld %i", &number_to_convert, &base);

				while (number_to_convert != 0)
				{
					converted_number[index] = number_to_convert % base;
					number_to_convert = number_to_convert / base;
					++index;
				}

				--index;  /* back up to last entry in the array */
				printf("\n\nConverted Number = ");
				for (; index >= 0; index--) /* go backward through array */
				{
					printf("%c", base_digits[converted_number[index]]);
				}
				printf("\n");
				break;

			case 0:

				printf("Enter number and base (2-10): ");
				scanf("%ld %i", &number_to_convert, &base);

				while (number_to_convert != 0)
				{
					temp = (number_to_convert % 10) * (pow(base, index));
					converted_base_10 += temp;
					number_to_convert = number_to_convert / 10;
					++index;
				}
				printf("\n\nConverted Number = %d", converted_base_10);
				break;

			case -1:
				printf("Quitting...");
				break;

			default:
				printf("Invalid choice.\n");
				break;
				
		}
		
		printf("\n");
	} while (choice != -1);
}