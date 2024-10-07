#include <stdio.h>
/*
Name: Ruben Pino-Martinez
Course: EECS348
Lab Name: Lab 4- IDE, compiled programs
Date: 10/6/24
Objective: Convert users' temperatures based off their input and what they want outputed, putting weather advisories for each
*/

/* Conversion Functions */
float celsius_to_fahrenheit(float celsius) {
    return ((9.0 / 5.0) * celsius) + 32;}
float fahrenheit_to_celsius(float fahrenheit) {
    return (5.0 / 9.0) * (fahrenheit - 32);}
float celsius_to_kelvin(float celsius) {
    return celsius + 273.15;}
float kelvin_to_celsius(float kelvin) {
    return kelvin - 273.15;}
float fahrenheit_to_kelvin(float fahrenheit) {
    return (5.0 / 9.0) * (fahrenheit - 32) + 273.15;}
float kelvin_to_fahrenheit(float kelvin) {
    return (9.0 / 5.0) * (kelvin - 273.15) + 32;}

/* Function to categorize temperature and provide weather advisory */
void categorize_temperature(float celsius) {
    if (celsius < 0) {
        printf("Freezing Weather! Stay indoors!\n");
    }
    else if (celsius >= 0 && celsius <= 10) {
        printf("Chilly Day! Wear a coat!\n");
    }
    else if (celsius > 10 && celsius <= 25) {
        printf("Average Day! Maybe a jacket!\n");
    }
    else if (celsius > 25 && celsius <= 35) {
        printf("Hot Day! Whew! Quite the heat! Stay Hydrated!\n");
    }
    else {
        printf("Extreme Heat Warning! Stay inside and hydrate!\n");
    }
}

/* Validate Kelvin input */
int validate_kelvin(float temperature) {
    if (temperature < 0) {
        printf("Error: Negative Kelvin values are not allowed.\n");
        return 0;
    }
    return 1;
}

int main() {
    char temp_scale;
    printf("Enter the temperature scale you're using (F/C/K): ");
    scanf(" %c", &temp_scale);

    float temperature;
    printf("Enter the temperature value: ");
    scanf("%f", &temperature);

    /* End the program if invalid Kelvin input */
    if (temp_scale == 'K' && !validate_kelvin(temperature)) {
        return 1;  
    }

    char convert_to;
    printf("Enter the temperature scale you want to convert to (F/C/K): ");
    scanf(" %c", &convert_to);

    float converted_temp = 0;

    /* Perform conversion based off user input */
    if (temp_scale == 'C' && convert_to == 'F') {
        converted_temp = celsius_to_fahrenheit(temperature);
    }
    else if (temp_scale == 'C' && convert_to == 'K') {
        converted_temp = celsius_to_kelvin(temperature);
    }
    else if (temp_scale == 'F' && convert_to == 'C') {
        converted_temp = fahrenheit_to_celsius(temperature);
    }
    else if (temp_scale == 'F' && convert_to == 'K') {
        converted_temp = fahrenheit_to_kelvin(temperature);
    }
    else if (temp_scale == 'K' && convert_to == 'C') {
        converted_temp = kelvin_to_celsius(temperature);
    }
    else if (temp_scale == 'K' && convert_to == 'F') {
        converted_temp = kelvin_to_fahrenheit(temperature);
    }
    else {
        printf("Invalid conversion.\n");
        /* End the program if conversion is invalid */
        return 1;  
    }

    printf("Converted temperature: %.2f %c\n", converted_temp, convert_to);

    /* Need temperature in Celsius for categorizing*/
    float temp_in_celsius = converted_temp;
    if (convert_to == 'F') {
        temp_in_celsius = fahrenheit_to_celsius(converted_temp);
    }
    else if (convert_to == 'K') {
        temp_in_celsius = kelvin_to_celsius(converted_temp);
    }
    categorize_temperature(temp_in_celsius);
    return 0;
}
