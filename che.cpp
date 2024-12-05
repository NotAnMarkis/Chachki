#include <stdio.h>
#include <iostream>
#include <math.h>

int i, c, team, white = 12, black = 12;
//A  B  C  D  E  F  G  H
int deskinfo[8][8] = { {0, 1, 0, 1, 0, 1, 0, 1},  //1
                       {1, 0, 1, 0, 1, 0, 1, 0},  //2
                       {0, 1, 0, 1, 0, 1, 0, 1},  //3
                       {0, 0, 0, 0, 0, 0, 0, 0},  //4
                       {0, 0, 0, 0, 0, 0, 0, 0},  //5
                       {2, 0, 2, 0, 2, 0, 2, 0},  //6 
                       {0, 2, 0, 2, 0, 2, 0, 2},  //7 
                       {2, 0, 2, 0, 2, 0, 2, 0} };//8
int whitech[12][2] = { {0,1}, {0,3}, {0,5}, {0,7}, {1,0}, {1,2}, {1,4}, {1,6}, {2,1}, {2,3}, {2,5}, {2,7} };
int blackch[12][2] = { {5,0}, {5,2}, {5,4}, {5,6}, {6,1}, {6,3}, {6,5}, {6,7}, {7,0}, {7,2}, {7,4}, {7,6} };
void desk();
void movementwh();
void movementbl();
void aimove();

int main() {
    setlocale(LC_ALL, "Ru");
b:
    printf("Выберите цвет: \n1) Белые\n2) Чёрные\n");
    scanf_s("%d", &team);
    switch (team) {
    case 1: {
        printf("Вы выбрали белый цвет, вы ходите первым!\n");
        break;
    }
    case 2: {
        printf("Вы выбрали чёрный цвет!\n");
        break;
    }
    default: {
        printf("Вы ввели неправильное число!\n");
        goto b;
        break;
    }
    }

    while (white > 0 && black > 0) {
        if (team == 1) {
            desk();
            movementwh();
            aimove();
        }
        else {
            aimove();
            desk();
            movementbl();
        }
    }
    if (white == 0) {
        printf("Чёрные выиграли!");
    }
    else {
        printf("Белые выиграли!");
    }
    return 0;
}

void desk() {
    printf("\n.|ABCDEFGH");
    printf("\n----------");
    for (i = 0; i < 8; i++) {
        switch (i) {
        case 0: {
            printf("\n1|");
            break;
        }
        case 1: {
            printf("\n2|");
            break;
        }
        case 2: {
            printf("\n3|");
            break;
        }
        case 3: {
            printf("\n4|");
            break;
        }
        case 4: {
            printf("\n5|");
            break;
        }
        case 5: {
            printf("\n6|");
            break;
        }
        case 6: {
            printf("\n7|");
            break;
        }
        case 7: {
            printf("\n8|");
            break;
        }
        default: {
            break;
        }
        }
        for (c = 0; c < 8; c++) {
            if (deskinfo[i][c] == 0) {
                printf(".");
            }
            else if (deskinfo[i][c] == 1) {
                printf("W");
            }
            else if (deskinfo[i][c] == 2) {
                printf("B");
            }
        }
    }
}

void movementwh() {
    int beforestr, beforestol, afterstr, afterstol;
    char a[3];
be:
    printf("\nПожалуйста выбирите шашку (Ваш цвет: Белый) | 2 символа (Столбец Строка) без пробелов\n");
    scanf_s("%2s", a, (unsigned)_countof(a));
    if (!(int(a[0]) > 96 && int(a[0]) < 105 && int(a[1]) > 48 && int(a[1]) < 58)) {
        printf("Вы выбрали ячейку не находящуюся на доске!\n");
        goto be;
    }
    beforestr = (int(a[1]) - 49);
    beforestol = (int(a[0]) - 97);
    if (!(deskinfo[beforestr][beforestol] == 1 || deskinfo[beforestr][beforestol] == 3)) {
        printf("В данной клетке нету белой шашки!\n");
        goto be;
    }
af:
    if (deskinfo[beforestr][beforestol] == 3) {
        printf("Выберите клетку куда вы желаете переместить шашку (Это дамка) | 2 символа (Столбец Строка) без пробелов | Вы можете ходить по диагонали");
        printf("\nЧтобы отменить выбор шашки напишите: -1\n");
    }
    else if (deskinfo[beforestr][beforestol] == 1) {
        printf("Выберите клетку куда вы желаете переместить шашку | 2 символа (Столбец Строка) без пробелов | Вы можете ходить по диагонали на 1 клетку (Или на 2 клетки, если через чёрную), но не можете ходить назад!");
        printf("\nЧтобы отменить выбор шашки напишите: -1\n");
    }
    if (!(int(a[0]) > 96 && int(a[0]) < 105 && int(a[1]) > 48 && int(a[1]) < 58)) {
        printf("Вы выбрали ячейку не находящуюся на доске!\n");
        goto af;
    }
    scanf_s("%2s", a, (unsigned)_countof(a));
    if (int(a[0]) == 45) {
        goto be;
    }
    afterstol = (int(a[0]) - 97);
    afterstr = (int(a[1]) - 49);
    if (deskinfo[afterstr][afterstol] != 0) {
        printf("На данной клетке что-то стоит, нельзя сделать такой ход!\n");
        goto af;
    }
    if (deskinfo[beforestr][beforestol] == 1) {
        if (deskinfo[beforestr][beforestol] == 1 && deskinfo[afterstr][afterstol] == 0 && ((afterstr - beforestr) == 1 || (afterstol - beforestol) == 1 || afterstol - beforestol == -1)) {
            if ((afterstr - beforestr) / 2 == 1 && (afterstol - beforestol) / 2 == 1 || (afterstol - beforestol) / 2 == -1) {
                if ((afterstol - beforestol) / 2 == 1) {
                    if (deskinfo[afterstr - 1][afterstol - 1] == 2 || deskinfo[afterstr - 1][afterstol - 1] == 4) {
                        deskinfo[afterstr - 1][afterstol - 1] = 0;
                        printf("Вы срубили чёрную пешку!\n");
                        black--;
                        goto movewh;
                    }
                }
                if ((afterstol - beforestol) / 2 == -1) {
                    if (deskinfo[afterstr + 1][afterstol + 1] == 2 || deskinfo[afterstr + 1][afterstol + 1] == 4) {
                        deskinfo[afterstr + 1][afterstol + 1] = 0;
                        printf("Вы срубили чёрную пешку!\n");
                        black--;
                        goto movewh;
                    }
                }
                else {
                    printf("Вы не можете сделать данный ход!");
                    goto af;
                }
            }
        }
        if (deskinfo[beforestr][beforestol] == 1 && !(afterstr - beforestr == 1 && (afterstol - beforestol == 1 || afterstol - beforestol == -1))) {
            printf("Вы не можете сделать данный ход!");
            goto af;
        }
        if (deskinfo[beforestr][beforestol] == 3 && !(abs((afterstr - beforestr)) == abs((afterstol - beforestol)))) {
            printf("Вы не можете сделать данный ход!");
            goto af;
        }
    movewh:
        if (deskinfo[beforestr][beforestol] == 1) {
            deskinfo[afterstr][afterstol] = 1;
        }
        else {
            deskinfo[afterstr][afterstol] = 3;
        }
        deskinfo[beforestr][beforestol] = 0;
    }
}

void movementbl() {
    int beforestr, beforestol, afterstol, afterstr;
    char a[3];
be1:
    printf("\nПожалуйста выбирите шашку (Ваш цвет: Чёрный) | 2 символа (Столбец Строка) без пробелов\n");
    scanf_s("%2s", a, (unsigned)_countof(a));
    if (!(int(a[0]) > 96 && int(a[0]) < 105 && int(a[1]) > 48 && int(a[1]) < 58)) {
        printf("Вы выбрали ячейку не находящуюся на доске!\n");
        goto be1;
    }
    beforestr = (int(a[1]) - 49);
    beforestol = (int(a[0]) - 97);
    if (!(deskinfo[beforestr][beforestol] == 2 || deskinfo[beforestr][beforestol] == 4)) {
        printf("В данной клетке нету чёрной шашки!\n");
        goto be1;
    }
af1:
    if (deskinfo[beforestr][beforestol] == 4) {
        printf("Выберите клетку куда вы желаете переместить шашку (Это дамка) | 2 символа (Столбец Строка) без пробелов | Вы можете ходить по диагонали");
        printf("\nЧтобы отменить выбор шашки напишите: -1\n");
    }
    else if (deskinfo[beforestr][beforestol] == 2) {
        printf("Выберите клетку куда вы желаете переместить шашку | 2 символа (Столбец Строка) без пробелов | Вы можете ходить по диагонали на 1 клетку (Или на 2 клетки, если через чёрную), но не можете ходить назад!");
        printf("\nЧтобы отменить выбор шашки напишите: -1\n");
    }
    scanf_s("%2s", a, (unsigned)_countof(a));
    if (!(int(a[0]) > 96 && int(a[0]) < 105 && int(a[1]) > 48 && int(a[1]) < 58)) {
        printf("Вы выбрали ячейку не находящуюся на доске!\n");
        goto af1;
    }
    if (int(a[0]) == 45) {
        goto be1;
    }
    afterstol = (int(a[0]) - 97);
    afterstr = (int(a[1]) - 49);
    if (deskinfo[afterstr][afterstol] != 0) {
        printf("На данной клетке что-то стоит, нельзя сделать такой ход!\n");
        goto af1;
    }
    if (deskinfo[beforestr][beforestol] == 2) {
        if (deskinfo[beforestr][beforestol] == 2 && deskinfo[afterstr][afterstol] == 0 && ((afterstr - beforestr) == 2 || (afterstol - beforestol) == 2 || afterstol - beforestol == -2)) {
            if ((beforestr - beforestr) / 2 == 1 && (beforestol - afterstol) / 2 == 1 || (beforestol - afterstol) / 2 == -1) {
                if ((afterstol - beforestol) / 2 == 1) {
                    if (deskinfo[afterstr + 1][afterstol - 1] == 1 || deskinfo[afterstr + 1][afterstol - 1] == 3) {
                        deskinfo[afterstr + 1][afterstol - 1] = 0;
                        printf("Вы срубили белую пешку!\n");
                        white--;
                        goto movebl;
                    }
                }
                if ((afterstol - beforestol) / 2 == -1) {
                    if (deskinfo[beforestr - 1][beforestol - 1] == 1 || deskinfo[beforestr - 1][beforestol - 1] == 3) {
                        deskinfo[beforestr - 1][beforestol - 1] = 0;
                        printf("Вы срубили белую пешку!\n");
                        white--;
                        goto movebl;
                    }
                }
                else {
                    printf("Вы не можете сделать данный ход!\n");
                    goto af1;
                }
            }
        }
        if (deskinfo[beforestr][beforestol] == 2 && !(abs(afterstr - beforestr) == 1 && (afterstol - beforestol == 1 || afterstol - beforestol == -1))) {
            printf("Вы не можете сделать данный ход!\n");
            goto af1;
        }
        if (deskinfo[beforestr][beforestol] == 4 && !(abs((afterstr - beforestr)) == abs((afterstol - beforestol)))) {
            printf("Вы не можете сделать данный ход!\n");
            goto af1;
        }
    movebl:
        if (deskinfo[beforestr][beforestol] == 2) {
            deskinfo[afterstr][afterstol] = 2;
        }
        else {
            deskinfo[afterstr][afterstol] = 4;
        }
        deskinfo[beforestr][beforestol] = 0;
    }
}

void aimove() {
    int teamchance[12], bestmoveindex[12][2], bestmoveto[2];
    int diag1mov[7][2], diag2mov[7][2];
    int a, b, ach, bch, bestmoveindiag1, bestmoveindiag2;
    int maxindiag1 = -1, maxindiag2 = -1, maxforall = -1;
    int i, d, index;

    for (i = 0; i < 12; i++) {
        teamchance[i] = -1;
        bestmoveindex[i][0] = -1;
        bestmoveindex[i][1] = -1;
    }

    for (i = 0; i < 12; i++) {
        for (int res = 0; res < 7; res++) {
            for (int res2 = 0; res2 < 2; res2++) {
                diag1mov[res][res2] = -1;
                diag2mov[res][res2] = -1;
            }
        }

        a = whitech[i][0];
        b = whitech[i][1];
        if (deskinfo[a][b] == 0) {
            continue;
        }
        //{0,1}, {0,3}, {0,5}, {0,7}, {1,0}, {1,2}, {1,4}, {1,6}, {2,1}, {2,3}, {2,5}, {2,7}
        if (deskinfo[a][b] == 1) {
            // Check all possible moves for regular pieces {1,0}
            if (b + 1 == 8 && (deskinfo[a + 1][b - 1] == 1 || deskinfo[a + 1][b - 1] == 3)) {
                teamchance[i] = 0;
                continue;
            }
            else if (b - 1 == -1 && (deskinfo[a + 1][b + 1] == 1 || deskinfo[a + 1][b + 1] == 3)) {
                teamchance[i] = 0;
                continue;
            }
            else if ((deskinfo[a + 1][b + 1] == 1 || deskinfo[a + 1][b + 1] == 3) && (deskinfo[a + 1][b - 1] == 1 || deskinfo[a + 1][a - 1] == 3)) {
                teamchance[i] = 0;
                continue;
            }
            else if (deskinfo[a + 1][b - 1] == 0) {
                ach = a + 1;
                bch = b - 1;
                if (deskinfo[ach + 1][bch - 1] == 0 && deskinfo[ach + 1][bch + 1] == 0) {
                    teamchance[i] = 25;
                }
                else if ((deskinfo[ach + 1][bch - 1] == 2 && deskinfo[ach - 1][bch + 1] == 1 && deskinfo[ach + 1][bch + 1] == 0) || (deskinfo[ach + 1][bch + 1] == 2 && deskinfo[ach - 1][bch - 1] == 1 && deskinfo[ach + 1][bch - 1] == 0)) {
                    teamchance[i] = 35;
                }
                else if ((deskinfo[ach + 1][bch - 1] == 2 && deskinfo[ach - 1][bch + 1] == 0 && deskinfo[ach + 1][bch + 1] == 0) || (deskinfo[ach + 1][bch - 1] == 2 || deskinfo[ach + 1][bch - 1] == 0)) {
                    teamchance[i] = 15;
                }
                bestmoveindex[i][0] = ach;
                bestmoveindex[i][1] = bch;
            }
            else if (deskinfo[a + 1][b - 1] == 2 || deskinfo[a + 1][b - 1] == 4) {
                if (deskinfo[a + 2][b - 2] == 0) {
                    teamchance[i] = 90;
                    bestmoveindex[i][0] = a + 2;
                    bestmoveindex[i][1] = b - 2;
                }
            }
            else if (deskinfo[a + 1][b + 1] == 2 || deskinfo[a + 1][b + 1] == 4) {
                if (deskinfo[a + 2][b + 2] == 0) {
                    teamchance[i] = 90;
                    bestmoveindex[i][0] = a + 2;
                    bestmoveindex[i][1] = b + 2;
                }
            }
            else if (a + 1 == 7) {
                if (deskinfo[a + 1][b - 1] == 0) {
                    teamchance[i] = 75;
                    bestmoveindex[i][0] = a + 1;
                    bestmoveindex[i][1] = b - 1;
                }
                else if (deskinfo[a + 1][b + 1] == 0) {
                    teamchance[i] = 75;
                    bestmoveindex[i][0] = a + 1;
                    bestmoveindex[i][1] = b + 1;
                }
            }
            else if (b - 1 == 0) {
                if (deskinfo[a + 1][b - 1] == 0) {
                    teamchance[i] = 60;
                    bestmoveindex[i][0] = a + 1;
                    bestmoveindex[i][1] = b - 1;
                }
            }
            else if (b + 1 == 7) {
                if (deskinfo[a + 1][b + 1] == 0) {
                    teamchance[i] = 60;
                    bestmoveindex[i][0] = a + 1;
                    bestmoveindex[i][1] = b + 1;
                }
            }
        }
        else if (deskinfo[a][b] == 3) {
            // Check all possible moves for kings
            ach = a;
            bch = b;
            for (int chdiag = 0; chdiag < 7; chdiag++) {
                ach++;
                bch++;
                if (ach > 7 || bch > 7) {
                    break;
                }
                if (deskinfo[ach][bch] == 1 || deskinfo[ach][bch] == 3) {
                    break;
                }
                if (deskinfo[ach - 1][bch - 1] == 0) {
                    diag1mov[chdiag][0] = 25;
                    diag1mov[chdiag][1] = ((ach + 1) * 10) + (bch + 1);
                }
                else if ((deskinfo[ach - 1][bch - 1] == 2 && deskinfo[ach + 1][bch + 1] == 1 && deskinfo[ach - 1][bch + 1] == 0) ||
                    (deskinfo[ach - 1][bch + 1] == 2 && deskinfo[ach + 1][bch - 1] == 1 && deskinfo[ach - 1][bch - 1] == 0)) {
                    diag1mov[chdiag][0] = 35;
                    diag1mov[chdiag][1] = ((ach + 1) * 10) + (bch + 1);
                }
                else if ((deskinfo[ach - 1][bch - 1] == 2 && deskinfo[ach + 1][bch + 1] == 0 && deskinfo[ach - 1][bch + 1] == 0) ||
                    (deskinfo[ach - 1][bch - 1] == 2 && deskinfo[ach - 1][bch - 1] == 0)) {
                    diag1mov[chdiag][0] = 15;
                    diag1mov[chdiag][1] = ((ach + 1) * 10) + (bch + 1);
                }
                else if (deskinfo[ach][bch] == 2 || deskinfo[ach][bch] == 4) {
                    if (deskinfo[ach + 1][bch + 1] == 0) {
                        diag1mov[chdiag][0] = 90;
                        diag1mov[chdiag][1] = ((ach + 1 + 1) * 10) + (bch + 1);
                    }
                }
                else if (bch == 7) {
                    if (deskinfo[ach][bch] == 0) {
                        diag1mov[chdiag][0] = 60;
                        diag1mov[chdiag][1] = ((ach + 1) * 10) + (bch + 1);
                    }
                }
                else if (ach == 7) {
                    if (deskinfo[ach][bch] == 0) {
                        diag1mov[chdiag][0] = 60;
                        diag1mov[chdiag][1] = ((ach + 1) * 10) + (bch + 1);
                    }
                }
            }

            ach = a;
            bch = b;
            for (int chdiag = 0; chdiag < 7; chdiag++) {
                ach++;
                bch--;
                if (ach > 7 || bch < 0) {
                    break;
                }
                if (deskinfo[ach][bch] == 1 || deskinfo[ach][bch] == 3) {
                    break;
                }
                if (deskinfo[ach - 1][bch + 1] == 0) {
                    diag2mov[chdiag][0] = 25;
                    diag2mov[chdiag][1] = ((ach + 1) * 10) + (bch + 1);
                }
                else if ((deskinfo[ach - 1][bch + 1] == 2 && deskinfo[ach + 1][bch - 1] == 1 && deskinfo[ach - 1][bch - 1] == 0) ||
                    (deskinfo[ach - 1][bch - 1] == 2 && deskinfo[ach + 1][bch + 1] == 1 && deskinfo[ach - 1][bch + 1] == 0)) {
                    diag2mov[chdiag][0] = 35;
                    diag2mov[chdiag][1] = ((ach + 1) * 10) + (bch + 1);
                }
                else if ((deskinfo[ach - 1][bch + 1] == 2 && deskinfo[ach + 1][bch - 1] == 0 && deskinfo[ach - 1][bch - 1] == 0) ||
                    (deskinfo[ach - 1][bch + 1] == 2 && deskinfo[ach - 1][bch + 1] == 0)) {
                    diag2mov[chdiag][0] = 15;
                    diag2mov[chdiag][1] = ((ach + 1) * 10) + (bch + 1);
                }
                else if (deskinfo[ach][bch] == 2 || deskinfo[ach][bch] == 4) {
                    if (deskinfo[ach + 1][bch - 1] == 0) {
                        diag2mov[chdiag][0] = 90;
                        diag2mov[chdiag][1] = ((ach + 1 + 1) * 10) + (bch);
                    }
                }
                else if (bch == 0) {
                    if (deskinfo[ach][bch] == 0) {
                        diag2mov[chdiag][0] = 60;
                        diag2mov[chdiag][1] = ((ach + 1) * 10) + (bch + 1);
                    }
                }
                else if (ach == 7) {
                    if (deskinfo[ach][bch] == 0) {
                        diag2mov[chdiag][0] = 60;
                        diag2mov[chdiag][1] = ((ach + 1) * 10) + (bch + 1);
                    }
                }
            }

            for (d = 0; d < 7; d++) {
                if (diag1mov[d][0] == -1) {
                    break;
                }
                if (diag1mov[d][0] > maxindiag1) {
                    maxindiag1 = diag1mov[d][0];
                    bestmoveindiag1 = diag1mov[d][1];
                }
            }
            for (d = 0; d < 7; d++) {
                if (diag2mov[d][0] == -1) {
                    break;
                }
                if (diag2mov[d][0] > maxindiag2) {
                    maxindiag2 = diag2mov[d][0];
                    bestmoveindiag2 = diag2mov[d][1];
                }
            }
            if (maxindiag2 > maxindiag1) {
                teamchance[i] = maxindiag1;
                bestmoveindex[i][0] = bestmoveindiag1 / 10 - 1;
                bestmoveindex[i][1] = bestmoveindiag1 % 10 - 1;
            }
            else {
                teamchance[i] = maxindiag2;
                bestmoveindex[i][0] = bestmoveindiag2 / 10 - 1;
                bestmoveindex[i][1] = bestmoveindiag2 % 10 - 1;
            }
        }
    }

    for (i = 0; i < 12; i++) {
        if (maxforall < teamchance[i]) {
            maxforall = teamchance[i];
            bestmoveto[0] = bestmoveindex[i][0];
            bestmoveto[1] = bestmoveindex[i][1];
            index = i;
        }
    }

    int inaafter = bestmoveto[0];
    int inbafter = bestmoveto[1];
    int inabefore = whitech[index][0];
    int inbbefore = whitech[index][1];

    whitech[index][0] = inaafter;
    whitech[index][1] = inbbefore - 1;

    if (deskinfo[inaafter - 1][inbafter - 1] == 2 || deskinfo[inaafter - 1][inbafter - 1] == 4) {
        deskinfo[inaafter - 1][inbafter - 1] = 0;
    }
    else if (deskinfo[inaafter - 1][inbafter + 1] == 2 || deskinfo[inaafter - 1][inbafter + 1] == 4) {
        deskinfo[inaafter - 1][inbafter + 1] = 0;
    }
    if (deskinfo[inabefore][inbbefore] == 3) {
        deskinfo[inaafter][inbafter] = 3;
    }
    else {
        deskinfo[inaafter][inbafter] = 1;
    }
    deskinfo[inabefore][inbbefore] = 0;
}
