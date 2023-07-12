#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
//#include "pico/stdlib.h"

#define CONFIG_FILE "config.json"
#define MOISTURE_THRESHOLD 500   // Default moisture threshold value

void read_config_file(char* filename, int* config_values) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening config file: Empty config file!\n");
        return;
    }

    char line[100];
    while (fgets(line, sizeof(line), file) != NULL) {
        if (strncmp(line, "moisture_threshold", 19) == 0) {
            char* threshold_str = strtok(line, "=");
            threshold_str = strtok(NULL, "=");
            int threshold = atoi(threshold_str);
            config_values[0] = threshold;
        }
        else if (strncmp(line, "pump_duration=", 14) == 0) {
            char* duration_str = strtok(line, "=");
            duration_str = strtok(NULL, "=");
            int duration = atoi(duration_str);
            config_values[1] = duration;
        }
        else if (strncmp(line, "other_config_value=", 19) == 0) {
            char* value_str = strtok(line, "=");
            value_str = strtok(NULL, "=");
            int value = atoi(value_str);
            config_values[2] = value;
        }
    }

    fclose(file);
}

int main() {
    int config_values[3] = {0};

    read_config_file(CONFIG_FILE, config_values);

    printf("Moisture Threshold: %d\n", config_values[0]);
    printf("Pump Duration: %d\n", config_values[1]);
    printf("Other Config Value: %d\n", config_values[2]);

    return 0;
}


/*int main() {
    stdio_init_all();
    gpio_init(PUMP_PIN);
    gpio_set_dir(PUMP_PIN, GPIO_OUT);

    int moisture_threshold = read_config_file(CONFIG_FILE);
    printf("Moisture Threshold: %d\n", moisture_threshold);

    while (1) {
        time_t now = time(NULL);
        struct tm* timeinfo = localtime(&now);

        if (timeinfo->tm_hour == 18 && timeinfo->tm_min == 0) {
            int soil_moisture = read_soil_moisture();   
            printf("Soil Moisture: %d\n", soil_moisture);

            if (soil_moisture < moisture_threshold) {
                activate_pump();   
                sleep_ms(10000);   
                deactivate_pump(); 
            }
        }

        sleep_ms(1000);   // Sleep for 1 second before checking the time again
    }

    return 0;
}*/
