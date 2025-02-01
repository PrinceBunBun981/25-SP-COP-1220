#include <stdio.h>

int hurricane_category(float windSpeed) {
    if (windSpeed >= 157) {
        return 5;
    } else if (windSpeed >= 130) {
        return 4;
    } else if (windSpeed >= 111) {
        return 3;
    } else if (windSpeed >= 96) {
        return 2;
    } else if (windSpeed >= 74) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    float windSpeed;

    printf("Enter the wind speed in mph: ");
    scanf("%f", &windSpeed);

    switch (hurricane_category(windSpeed)) {
        case 5:
            printf("Category Five Hurricane\n");
            break;
        case 4:
            printf("Category Four Hurricane\n");
            break;
        case 3:
            printf("Category Three Hurricane\n");
            break;
        case 2:
            printf("Category Two Hurricane\n");
            break;
        case 1:
            printf("Category One Hurricane\n");
            break;
        default:
            printf("Not a Hurricane\n");
            break;
    }

    return 0;
}
