/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_STR 100

void display_diseases();
void display_symptoms(int disease_choice);
void display_treatment_plan(int disease_choice);
float calculate_costs(int disease_choice);

int main() {
    char continue_program[MAX_STR];

   do {
        int disease_choice;
        char user_symptoms[MAX_STR] = "", severity[MAX_STR], allergies[MAX_STR], pre_existing[MAX_STR], answer[MAX_STR];

        printf("\n=== Medical Assistance System ===\n\n");

        display_diseases();
        printf("Select a condition (1-10) or type 0 to input your own symptoms: ");
        while (scanf("%d", &disease_choice) != 1 || (disease_choice < 0 || disease_choice > 10)) {
            printf("Invalid selection. Please choose a valid number between 0 and 10:\n ");
            while(getchar() != '\n');  
        }
     

        if (disease_choice == 0) {
            printf("\nPlease describe your symptoms: ");
            scanf(" %s", user_symptoms);

            if (strcasecmp(user_symptoms, "fever") || strcasecmp(user_symptoms, "cough") || strcasecmp(user_symptoms, "sore throat") || strcasecmp(user_symptoms, "Sneezing") || strcasecmp(user_symptoms, "Itching")) {
                printf("\nMatching symptoms found. Proceeding with diagnosis.\n");
                disease_choice = 4;
            } else {
                printf("\nSymptoms not found in database. Consult a doctor for assistance.\n");
                continue;
            }
        } else if (disease_choice < 1 || disease_choice > 10) {
            printf("Invalid selection. Please choose a valid condition.\n");
            continue;
        }

        do {
            display_symptoms(disease_choice);
            printf("\nDo these symptoms match your condition? (Yes/No): ");
            scanf("%s", answer);

            if (strcasecmp(answer, "no") == 0) {
                printf("\nConsult a doctor for an accurate diagnosis.\n");
            } else if (strcasecmp(answer, "yes") != 0) {
                printf("Please enter a valid response (Yes or No).\n");
            }
        } while (strcasecmp(answer, "yes") != 0 && strcasecmp(answer, "no") != 0);

        printf("\nRate severity (Mild/Moderate/Severe): ");
        scanf("%s", severity);
        while (strcasecmp(severity, "Mild") != 0 && strcasecmp(severity, "Moderate") != 0 && strcasecmp(severity, "Severe") != 0) {
            printf("Invalid input. Enter only Mild, Moderate, or Severe: ");
            scanf("%s", severity);
        }
            printf("\nList any pre-existing conditions (or type 'None'): ");
        scanf("%s", pre_existing);
         while (strspn(pre_existing, "0123456789") != 0 || (strcasecmp(pre_existing, "None") != 0 && strlen(pre_existing) == 0)) {
            printf("Invalid input. Please enter valid text or 'None': ");
            scanf("%s", pre_existing);
        }
        
        printf("List any allergies (or type 'None'): ");
        scanf("%s", allergies);
        while (strspn(allergies, "0123456789") != 0 || (strcasecmp(allergies, "None") != 0 && strlen(allergies) == 0)) {
            printf("Invalid input. Please enter valid text or 'None': ");
            scanf("%s", allergies);
        }

        printf("\n=== Diagnosis and Treatment Plan ===\n");
        display_treatment_plan(disease_choice);

        printf("\nTotal Estimated Cost: RS%.2f\n", calculate_costs(disease_choice));

        printf("\nImportant Notes:\n");
        printf("1. Please consult a healthcare professional for an accurate diagnosis.\n");
        printf("2. This is a preliminary assessment only.\n");
        printf("3. If symptoms worsen, seek immediate medical attention.\n");

        if (strcasecmp(pre_existing, "None") != 0) {
            printf("\nPre-existing Conditions: %s\n",pre_existing);
        }

        if (strcasecmp(allergies, "None") != 0) {
            printf("Allergy Warning: Inform your doctor about: %s\n", allergies);
        }

        printf("\nWould you like another diagnosis? (Yes/No): ");
        scanf("%s", continue_program);

    } while (strcasecmp(continue_program, "yes") == 0);

    printf("\nThank you for using the Medical Assistance System. Stay healthy!\n");
    return 0;
}

void display_diseases() {
    printf("Available conditions:\n");
    printf("1. Common Cold\n");
    printf("2. Headache\n");
    printf("3. Stomach Ache\n");
    printf("4. Fever\n");
    printf("5. Skin Allergy\n");
    printf("6. Diabetes\n");
    printf("7. Hypertension\n");
    printf("8. Back Pain\n");
    printf("9. Sore Throat\n");
    printf("10. Eye Strain\n\n");
}

void display_symptoms(int disease_choice) {
    printf("\nSymptoms:\n");
    switch (disease_choice) {
        case 1: printf("- Sneezing, Cough, Sore throat\n"); break;
        case 2: printf("- Headache, Nausea, Dizziness\n"); break;
        case 3: printf("- Abdominal pain, Nausea, Bloating\n"); break;
        case 4: printf("- Fever, Chills, Weakness\n"); break;
        case 5: printf("- Rash, Itching, Redness\n"); break;
        case 6: printf("- Frequent urination, Fatigue, Hunger\n"); break;
        case 7: printf("- High BP, Chest pain, Dizziness\n"); break;
        case 8: printf("- Back pain, Stiffness, Radiating pain\n"); break;
        case 9: printf("- Throat pain, Cough, Swelling\n"); break;
        case 10: printf("- Eye strain, Blurred vision, Dry eyes\n"); break;
        default: printf("No symptoms available.\n");
    }
}

void display_treatment_plan(int disease_choice) {
    printf("\nTreatment Plan:\n");
    switch (disease_choice) {
        case 1: // Common Cold
            printf("- Antihistamine: 10mg daily\n- Decongestant: Every 6 hours\n- Vitamin C: 500mg twice daily\n");
            printf("- Exercise: Gentle stretching and walking\n");
            printf("- Avoid: Cold drinks, dairy, and sugary foods\n");
            printf("- Recommended: Warm tea with honey and ginger\n");
            break;
        case 2: // Headache
            printf("- Ibuprofen: 400mg as needed\n- Acetaminophen: 500mg every 6 hours\n- Stay calm\n");
            printf("- Exercise: Gentle neck and shoulder stretches\n");
            printf("- Avoid: Bright lights, loud noises, and caffeine\n");
            printf("- Recommended: Drink plenty of water, herbal teas\n");
            break;
        case 3: // Stomach Ache
            printf("- Antacid: 10ml after meals\n- Probiotics: One capsule daily\n- Anti-nausea medication: As needed\n");
            printf("- Exercise: Light walking and gentle stomach massages\n");
            printf("- Avoid: Spicy, greasy, and acidic foods\n");
            printf("- Recommended: Eat bland foods like crackers, toast, and bananas\n");
            break;
        case 4: // Fever
            printf("- Paracetamol: 500mg every 6 hours\n- Ibuprofen: 400mg as needed\n");
            printf("- Exercise: Rest and avoid strenuous physical activity\n");
            printf("- Avoid: Caffeinated drinks, alcohol, and spicy foods\n");
            printf("- Recommended: Drink fluids like water, clear soups, and herbal teas\n");
            break;
        case 5: // Skin Allergy
            printf("- Antihistamine: 10mg daily\n- Topical cream: Apply twice daily\n- Calamine lotion: As needed\n");
            printf("- Exercise: Avoid sweating or prolonged sun exposure\n");
            printf("- Avoid: Potential allergens, harsh soaps, and perfumes\n");
            printf("- Recommended: Drink water to keep skin hydrated, use gentle skincare products\n");
            break;
        case 6: // Diabetes
            printf("- Metformin: 500mg twice daily\n- Blood glucose meter: Test 4 times daily\n- Test strips: Box of 50\n");
            printf("- Exercise: Regular moderate exercise, like walking, swimming, or cycling\n");
            printf("- Avoid: High-sugar foods and refined carbs\n");
            printf("- Recommended: Eat low glycemic index foods, drink water and herbal teas\n");
            break;
        case 7: // Hypertension
            printf("- Amlodipine: 5mg daily\n- Blood pressure monitor: Check twice daily\n");
            printf("- Exercise: Cardiovascular exercises like walking, cycling, or swimming\n");
            printf("- Avoid: High-salt foods, processed foods, and excessive alcohol\n");
            printf("- Recommended: Eat potassium-rich foods, drink plenty of water\n");
            break;
        case 8: // Back Pain
            printf("- Pain reliever: As needed\n- Muscle relaxant: Twice daily\n- Hot/cold pack: As needed\n");
            printf("- Exercise: Stretching exercises, yoga, and strengthening exercises for the back\n");
            printf("- Avoid: Heavy lifting and prolonged sitting\n");
            printf("- Recommended: Drink anti-inflammatory herbal teas like ginger or turmeric tea\n");
            break;
        case 9: // Sore Throat
            printf("- Throat lozenges: As needed\n- Pain reliever: Every 6 hours\n- Throat spray: 4-6 times daily\n");
            printf("- Exercise: Gentle neck stretches, avoid straining voice\n");
            printf("- Avoid: Acidic drinks, spicy foods, and smoking\n");
            printf("- Recommended: Warm water with honey and lemon, herbal teas\n");
            break;
        case 10: // Eye Strain
            printf("- Artificial tears: As needed\n- Eye vitamins: Daily\n");
            printf("- Exercise: Eye relaxation exercises, 20-20-20 rule (every 20 minutes, look at something 20 feet away for 20 seconds)\n");
            printf("- Avoid: Prolonged screen time without breaks, excessive use of digital devices\n");
            printf("- Recommended: Drink water to stay hydrated, and consume foods rich in vitamin A (carrots, spinach)\n");
            break;
        default:
            printf("No treatment available for this condition.\n");
    }
}

float calculate_costs(int disease_choice) {
    float consultation_fee, medication_cost;

    switch (disease_choice) {
        case 1:
            consultation_fee = 50.0;
            medication_cost = 15.0 + 12.0 + 8.0;
            break;
        case 2:
            consultation_fee = 40.0;
            medication_cost = 10.0 + 8.0;
            break;
        case 3:
            consultation_fee = 60.0;
            medication_cost = 12.0 + 20.0 + 15.0;
            break;
        case 4:
            consultation_fee = 45.0;
            medication_cost = 10.0 + 12.0;
            break;
        case 5:
            consultation_fee = 70.0;
            medication_cost = 15.0 + 25.0 + 10.0;
            break;
        case 6:
            consultation_fee = 100.0;
            medication_cost = 30.0 + 50.0 + 40.0;
            break;
        case 7:
            consultation_fee = 90.0;
            medication_cost = 25.0 + 60.0;
            break;
        case 8:
            consultation_fee = 80.0;
            medication_cost = 15.0 + 20.0 + 10.0;
            break;
        case 9:
            consultation_fee = 55.0;
            medication_cost = 8.0 + 10.0 + 12.0;
            break;
        case 10:
            consultation_fee = 65.0;
            medication_cost = 15.0 + 20.0;
            break;
        default:
            consultation_fee = 0.0;
            medication_cost = 0.0;
    }

    return consultation_fee + medication_cost;
}
