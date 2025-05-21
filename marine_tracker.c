#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --- Types ---
typedef enum { FISH, MAMMAL, CRUSTACEAN, MOLLUSK } SpeciesType;

typedef union {
    float averageWeight;
    int typicalCount;
} ExtraInfo;

typedef struct {
    char name[50];
    SpeciesType type;
    float length;
    ExtraInfo info;
} MarineRecord;

// --- Globals & Array Management ---
int capacity = 10;
int count = 0;
MarineRecord *records;

void init_array() {
    records = malloc(sizeof(MarineRecord) * capacity);
    if (!records) { perror("malloc"); exit(EXIT_FAILURE); }
}

void display_record(const MarineRecord *r, int idx) {
    const char *names[] = {"Fish","Mammal","Crustacean","Mollusk"};
    printf("[%d] %s (%s), %.1f cm, ", idx+1, r->name, names[r->type], r->length);
    if (r->type == MAMMAL)
        printf("Avg Wt: %.2f kg\n", r->info.averageWeight);
    else
        printf("School: %d\n", r->info.typicalCount);
}

void list_all() {
    if (count == 0) { printf("No records.\n"); return; }
    for (int i = 0; i < count; i++) display_record(&records[i], i);
}


void ensure_capacity() {
    if (count >= capacity) {
        capacity *= 2;
        records = realloc(records, sizeof(MarineRecord) * capacity);
        if (!records) { perror("realloc"); exit(EXIT_FAILURE); }
    }
}

void print_menu() {
    printf("\n=== Marine Species Tracker ===\n");
    printf("1) Add Record\n2) List All Records\n3) Search by Species\n");
    printf("4) Delete Record\n5) Show Statistics\n6) Exit\n");
}

int get_choice(int min, int max) {
    int choice;
    while (1) {
        printf("Enter choice (%d-%d): ", min, max);
        if (scanf("%d", &choice) != 1) {
            printf("Invalid. Try again.\n"); while (getchar()!='\n');
        } else if (choice < min || choice > max) {
            printf("Out of range. Try again.\n");
        } else { while (getchar()!='\n'); return choice; }
    }
}

void search_by_species() {
    printf("Select species:\n0 = Fish\n1 = Mammal\n2 = Crustacean\n3 = Mollusk\n");
    int t = get_choice(0,3), found = 0;
    for (int i = 0; i < count; i++)
        if (records[i].type == t) {
            display_record(&records[i], i);
            found++;
        }
    if (!found) printf("No matches.\n");
}

void delete_record() {
    list_all();
    if (count == 0) return;
    printf("Delete record #: ");
    int idx = get_choice(1, count) - 1;
    for (int i = idx; i < count - 1; i++)
        records[i] = records[i + 1];
    count--;
    printf("Deleted.\n");
}

float compute_avg_length() {
    float sum = 0;
    for (int i = 0; i < count; i++) sum += records[i].length;
    return count ? sum / count : 0;
}

void show_stats() {
    float avg = compute_avg_length();
    int species_counts[4] = {0};
    for (int i = 0; i < count; i++)
        species_counts[records[i].type]++;

    printf("\n--- Stats ---\nAverage Length: %.2f cm\n", avg);
    const char *names[] = {"Fish","Mammal","Crustacean","Mollusk"};
    for (int i = 0; i < 4; i++)
        printf("%s: %d\n", names[i], species_counts[i]);
}

void prompt_new_record() {
    MarineRecord rec;
    printf("Enter name: ");
    fgets(rec.name, sizeof(rec.name), stdin);
    rec.name[strcspn(rec.name, "\n")] = '\0';

    printf("Enter Species:\n0 = Fish\n1 = Mammal\n2 = Crustacean\n3 = Mollusk\n");
    rec.type = get_choice(0,3);

    printf("Length (cm): "); scanf("%f", &rec.length); while(getchar()!='\n');

    if (rec.type == MAMMAL) {
        printf("Average weight (kg): ");
        scanf("%f", &rec.info.averageWeight);
    } else {
        printf("Typical school count: ");
        scanf("%d", &rec.info.typicalCount);
    }
    while(getchar()!='\n');

    ensure_capacity();
    records[count++] = rec;
    printf("Record added!\n");
}

int main() {
        init_array();
    int choice;
    do {
        print_menu();
        choice = get_choice(1,6);
        switch (choice) {
            case 1: prompt_new_record(); break;
            case 2: list_all();         break;
            case 3: search_by_species();break;
            case 4: delete_record();    break;
            case 5: show_stats();       break;
        }

    } while (choice != 6);

    free(records);
    printf("Goodbye!\n");
    return 0;
}