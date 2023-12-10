#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct for jewelry
struct Jewelry {
    char type[20];
    char specificType[20];
    float gram;
    char material[20];
    float price;
};

// Function to input jewelry details based on type
void inputJewelryDetails(struct Jewelry *jewelry) {
    // Prompt the user for jewelry type
    printf("Enter Jewelry type (Ring, Earring, Necklace, Bracelet, Pendant): ");
    scanf("%s", jewelry->type);

    // Prompt the user for specific jewelry type based on the selected type
    if (strcmp(jewelry->type, "Ring") == 0) {
        printf("Enter Specific Jewelry type (Openring, Nailring, Cocktailring, Midiring, Eternityring): ");
        scanf("%s", jewelry->specificType);
        if ((strcmp(jewelry->specificType, "Openring") == 0) || (strcmp(jewelry->specificType, "Nailring") == 0) || (strcmp(jewelry->specificType, "Cocktailring") == 0) || 
        (strcmp(jewelry->specificType, "Midiring") == 0) || (strcmp(jewelry->specificType, "Eternityring") == 0)) {
            // Prompt the user for gram
            printf("Enter Gram size: 3-20 ");
            scanf("%f", &jewelry->gram);
            if(jewelry->gram < 3 || jewelry->gram > 20) {
                fprintf(stderr, "Invalid Gram size. Exiting...\n");
                exit(1);                
            }
        } else {
            fprintf(stderr, "Invalid Specific Jewelry type. Exiting...\n");
            exit(1);
        }
    } else if (strcmp(jewelry->type, "Earring") == 0) {
        printf("Enter Specific Jewelry type (Cartilage, Chandelier, Earcuffs): ");
        scanf("%s", jewelry->specificType);
        if ((strcmp(jewelry->specificType, "Cartilage") == 0) || (strcmp(jewelry->specificType, "Chandelier") == 0) || (strcmp(jewelry->specificType, "Earcuffs") == 0)) {
            // Prompt the user for gram
            printf("Enter Gram size: 4-20 ");
            scanf("%f", &jewelry->gram);
            if(jewelry->gram < 4 || jewelry->gram > 20) {
                fprintf(stderr, "Invalid Gram size. Exiting...\n");
                exit(1);                
            }
        } else {
            fprintf(stderr, "Invalid Specific Jewelry type. Exiting...\n");
            exit(1);
        }
    } else if (strcmp(jewelry->type, "Necklace") == 0) {
        printf("Enter Specific Jewelry type (Fullset, Halfset, Noset, Choker): ");
        scanf("%s", jewelry->specificType);
        if ((strcmp(jewelry->specificType, "Fullset") == 0) || (strcmp(jewelry->specificType, "Halfset") == 0) || (strcmp(jewelry->specificType, "Noset") == 0) || 
        (strcmp(jewelry->specificType, "Choker") == 0)) {
            // Prompt the user for gram
            printf("Enter Gram size: 12-60 ");
            scanf("%f", &jewelry->gram);
            if(jewelry->gram < 12 || jewelry->gram > 60) {
                fprintf(stderr, "Invalid Gram size. Exiting...\n");
                exit(1);                
            }
        } else {
            fprintf(stderr, "Invalid Specific Jewelry type. Exiting...\n");
            exit(1);
        }
    } else if (strcmp(jewelry->type, "Bracelet") == 0) {
        printf("Enter Specific Jewelry type (Stiff, Cuff, Flexible): ");
        scanf("%s", jewelry->specificType);
        if ((strcmp(jewelry->specificType, "Stiff") == 0) || (strcmp(jewelry->specificType, "Cuff") == 0) || (strcmp(jewelry->specificType, "Flexible") == 0)) {
            // Prompt the user for gram
            printf("Enter Gram size: 8-40 ");
            scanf("%f", &jewelry->gram);
            if(jewelry->gram < 8 || jewelry->gram > 40) {
                fprintf(stderr, "Invalid Gram size. Exiting...\n");
                exit(1);                
            }
        } else {
            fprintf(stderr, "Invalid Specific Jewelry type. Exiting...\n");
            exit(1);
        }
    } else if (strcmp(jewelry->type, "Pendant") == 0) {
        printf("Enter Specific Jewelry type (Name, Alphabet): ");
        scanf("%s", jewelry->specificType);
        if ((strcmp(jewelry->specificType, "Name") == 0) || (strcmp(jewelry->specificType, "Alphabet") == 0)) {
            // Prompt the user for gram
            printf("Enter Gram size: 20-40 ");
            scanf("%f", &jewelry->gram);
            if(jewelry->gram < 20 || jewelry->gram > 40) {
                fprintf(stderr, "Invalid Gram size. Exiting...\n");
                exit(1);                
            }
        } else {
            fprintf(stderr, "Invalid Specific Jewelry type. Exiting...\n");
            exit(1);
        }
    } else {
        fprintf(stderr, "Invalid Jewelry type. Exiting...\n");
        exit(1);
    }

    // Prompt the user for material
    printf("Enter Material type (Gold, Silver, Platinum): ");
    scanf("%s", jewelry->material);
    if(strcmp(jewelry->material, "Gold") ==0) {
        jewelry->price = 60.0 * jewelry->gram;
    } else if(strcmp(jewelry->material, "Silver") ==0) {
        jewelry->price = 2.0 * jewelry->gram;
    } else if(strcmp(jewelry->material, "Platinum") ==0) {
        jewelry->price = 27.0 * jewelry->gram;
    } else {
        fprintf(stderr, "Invalid Jewelry type. Exiting...\n");
        exit(1);
    }
}

// Function to print and save the output
void printAndSaveOutput(const struct Jewelry *jewelry) {
    // Print the entered data and calculated price
    printf("Jewelry Type: %s\n", jewelry->type);
    printf("Specific Type: %s\n", jewelry->specificType);
    printf("Gram: %.2f\n", jewelry->gram);
    printf("Material: %s\n", jewelry->material);
    printf("Calculated Price: %.2f\n", jewelry->price);

    // Save the output to "Output.txt"
    FILE *outputFile = fopen("OutputData.txt", "w");
    if (outputFile == NULL) {
        fprintf(stderr, "Error opening OutputData.txt file for writing.\n");
        exit(1);
    }

    fprintf(outputFile, "Jewelry Type: %s\n", jewelry->type);
    fprintf(outputFile, "Specific Type: %s\n", jewelry->specificType);
    fprintf(outputFile, "Gram: %.2f\n", jewelry->gram);
    fprintf(outputFile, "Material: %s\n", jewelry->material);
    fprintf(outputFile, "Calculated Price: %.2f\n", jewelry->price);

    fclose(outputFile);
}

int main() {
    printf("Here is listed all available materials and jewellery types\n\n");
    printf("Material:   Gold-60$ per gram, Silver-2$ per gram, Platinum-27$ per grame\n\n");
    printf("Type:       Ring: Openring Nailring Cocktailring Midiring Eternityring (3-20 gram)\n");
    printf("            Earring: Cartilage Chandelier Earcuffs (4-20 gram)\n");
    printf("            Necklace: Fullset Halfset Noset Choker (12-60 gram)\n");
    printf("            Bracelet: Stiff Cuff Flexible (8-40 gram)\n");
    printf("            Pendant: Name Alphabet (20-40 gram)\n\n");
    // Read user input
    struct Jewelry *jewelryData = (struct Jewelry *)malloc(sizeof(struct Jewelry));
    if (jewelryData == NULL) {
        fprintf(stderr, "Memory allocation error. Exiting...\n");
        return 1;
    }

    // Input jewelry details based on type
    inputJewelryDetails(jewelryData);

    // Print and save the output
    printAndSaveOutput(jewelryData);

    // Free dynamically allocated memory
    free(jewelryData);

    return 0;
}


