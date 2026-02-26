#include <stdio.h>
#include <conio.h> //for getch();
#include <unistd.h> //for sleep();
struct student{
    char name[50], id[50];
    float marks[3][4];
    float cgpa;
};
int i, row, col, n=10;

void write_input(struct student st[]){
    FILE *input;
    input = fopen("input.txt","w");
    //Taking input
    for( i=0; i<n; i++){
        if(i>0)printf("\n");

        printf("Student - %d :\n--------------\n", i+1);
        printf("Name: ");gets(st[i].name);
        printf("ID: ");gets(st[i].id);
        printf("Marks:\n");
        for( row=0; row<3; row++){
            printf("Subject-%d : ", row+1);
            for( col=0; col<4; col++){
                scanf("%f", &st[i].marks[row][col]);
            }
        }
        printf("CGPA: ");scanf("%f", &st[i].cgpa);
        fflush(stdin);
    }
    //Printing in the input
    for( i=0; i<n; i++){
        fprintf(input, "%s\n", st[i].name,input);
        fprintf(input,"%s\n", st[i].id);
        for( row=0; row<3; row++){
            for( col=0; col<4; col++){
                fprintf(input,"%.2f ", st[i].marks[row][col]);
            }
            fprintf(input, "\n");
        }
        fprintf(input, "%.2f\n", st[i].cgpa);
    }
    fclose(input);
}

void print(struct student st[]){
    FILE *output;
    output = fopen("output.txt","w");

    for( i=0; i<n; i++){
        if(i>0)fprintf(output,"\n\n");

        fprintf(output, "Student %d:", i+1);
        fprintf(output, "\nName: %s", st[i].name);
        fprintf(output,"\nID: %s", st[i].id);
        for( row=0; row<3; row++){
                fprintf(output,"\nSubject %d marks: ", row+1);
            for ( col=0; col<4; col++){
                fprintf(output,"%.2f ", st[i].marks[row][col]);
            }
        }
        fprintf(output,"\nCGPA: %.2f", st[i].cgpa);
    }
    fclose(output);
}

void printtotal(struct student st[]){
    float sub_sum1 = 0, sub_sum2 = 0, sub_sum3 = 0;
    FILE *output;
    output = fopen("output.txt","a");

    for( i=0; i<n; i++){
        if(i==0)fprintf(output, "\n\n\n");
        sub_sum1 = st[i].marks[0][0]+st[i].marks[0][1]+st[i].marks[0][2]+st[i].marks[0][3];
        sub_sum2 = st[i].marks[1][0]+st[i].marks[1][1]+st[i].marks[1][2]+st[i].marks[1][3];
        sub_sum3 = st[i].marks[2][0]+st[i].marks[2][1]+st[i].marks[1][2]+st[i].marks[2][3];

        fprintf(output, "\nStudent %d: ", i+1);
        fprintf(output, "Subject 1 total: %.2f", sub_sum1);
        fprintf(output, "\n\t   Subject 2 total: %.2f", sub_sum2);
        fprintf(output, "\n\t   Subject 3 total: %.2f\n", sub_sum3);
    }
    fclose(output);
}

int maxCGPA(struct student st[]){
    FILE *output;
    output = fopen("output.txt", "a");
    float max = 0;
    for( i=0; i<n; i++){
        if(st[i].cgpa>max)
            max = st[i].cgpa;
    }
    fprintf(output, "\n\n\n\nMaximum CGPA: %.1f", max);
    fclose(output);
}
int minCGPA(struct student st[]){
    FILE *output;
    output = fopen("output.txt", "a");
    float max = 0, min = 0;
    for( i=0; i<n; i++){
        if(st[i].cgpa>max)
            max = st[i].cgpa;
    }
    min = max;
    for( i=0; i<n; i++){
        if(st[i].cgpa<min)
            min = st[i].cgpa;
    }
    fprintf(output, "\nMinimum CGPA: %.1f", min);
    fclose(output);
}

int main(){
    struct student st[10];

    write_input(st); //Takes data from the user & writes it into the input.txt

    //Reads data from Input.txt
    FILE *input;
    input = fopen("input.txt","r");
    for( i=0; i<n; i++){
        fscanf(input, "%s", st[i].name);
        fscanf(input,"%s", st[i].id);
        for( row=0; row<3; row++){
            for ( col=0; col<4; col++){
                fscanf(input,"%f",&st[i].marks[row][col]);
            }
        }
        fscanf(input,"%f",&st[i].cgpa);
    }
    fclose(input);

    print(st); //writes data into the output.txt
    printtotal(st); //appends total marks into the output.txt
    maxCGPA(st); //appends maximum cgpa into the output.txt
    minCGPA(st); //appends minimum cgpa into the output.txt

    sleep(1);
    printf("\n\nData Reading Complete.\n\n");
    getch();
}
