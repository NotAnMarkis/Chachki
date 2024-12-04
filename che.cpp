 void aimove() {
    int teamchance[12], whomove, d, bestmoveindex[12][2], bestmoveto[2], a, b, ach, bch, bestmoveindiag1, bestmoveindiag2, diag1mov[7][2], diag2mov[7][2], res, res2, chdiag, safech, maxindiag1 = -1, maxindiag2 = -1, maxforall = -1, inabefore, inbbefore, inaafter, inbafter;
    if (team == 1) {
 
    }
    else {
        /*  (--)(-=)(-+)
               \ | /
                \|/
           (=-)--+--(=+)    <-- Система координации 1 - это строка (a) 2 - столбец (b)
                /|\
               / | \
            (+-)(+=)(++)  */
        for (i = 0; i < 12; i++) {
            for (res = 0; res < 7; res++) {
                for (res2 = 0; res2 < 2; res2++) {
                    diag1mov[res][res2] = -1;
                    diag2mov[res][res2] = -1;
                }
            }
            a = whitech[i][0];
            b = whitech[i][1];
            if (deskinfo[a][b] == 0) {
                break;
            }
 
            if (deskinfo[a][b] == 1) {
                if ((deskinfo[a + 1][b - 1] == 1 || deskinfo[a + 1][b - 1] == 3) && (deskinfo[a + 1][b + 1] == 1 || deskinfo[a + 1][b + 1] == 3)) {
                    teamchance[i] = 0;
                    bestmoveindex[i][0] = -1;
                }
                else if (deskinfo[a + 1][b - 1] == 0) {
                    ach = a + 1;
                    bch = b - 1;
                    //ход без последствий
                    if (deskinfo[ach + 1][bch - 1] == 0 && deskinfo[ach + 1][bch + 1] == 0) {
                        teamchance[i] = 25;
                        bestmoveindex[i][0] = ach;
                        bestmoveindex[i][1] = bch;
                    }
 
                    //ход с встречей с врагом но с защитой от смертьи
                    else if ((deskinfo[ach + 1][bch - 1] == 2 && deskinfo[ach - 1][bch + 1] == 1 && deskinfo[ach + 1][bch + 1] == 0) || (deskinfo[ach + 1][bch + 1] == 2 && deskinfo[ach - 1][bch - 1] == 1 && deskinfo[ach + 1][bch - 1] == 0)) {
                        teamchance[i] = 35;
                        bestmoveindex[i][0] = ach;
                        bestmoveindex[i][1] = bch;
                    }
 
                    //ход с встречей с врагом но без защиты
                    else if ((deskinfo[ach + 1][bch - 1] == 2 && deskinfo[ach - 1][bch + 1] == 0 && deskinfo[ach + 1][bch + 1] == 0) || (deskinfo[ach + 1][bch - 1] == 2 && deskinfo[ach + 1][bch - 1] == 2 && (deskinfo[ach - 1][bch - 1] == 0 || deskinfo[ach - 1][bch + 1] == 0))) {
                        teamchance[i] = 15;
                        bestmoveindex[i][0] = ach;
                        bestmoveindex[i][1] = bch;
                    }
                }
                //ход на убийство
                else if (deskinfo[a + 1][b - 1] == 2 || deskinfo[a + 1][b - 1] == 4) {
                    if (deskinfo[a + 2][b - 2] == 0) {
                        teamchance[i] = 90;
                        bestmoveindex[i][0] = a + 2;
                        bestmoveindex[i][1] = b - 2;
                    }
                }
                //ход на убийство
                else if (deskinfo[a + 1][b + 1] == 2 || deskinfo[a + 1][b + 1] == 4) {
                    if (deskinfo[a + 2][b + 2] == 0) {
                        teamchance[i] = 90;
                        bestmoveindex[i][0] = a + 2;
                        bestmoveindex[i][1] = b + 2;
                    }
                }
                //ход на становление дамки
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
                //ход к стене
                else if (b - 1 == 0) {
                    if (deskinfo[a + 1][b - 1] == 0) {
                        teamchance[i] = 60;
                        bestmoveindex[i][0] = a + 1;
                        bestmoveindex[i][1] = b - 1;
                    }
                }
                //ход к стене
                else if (b + 1 == 7) {
                    if (deskinfo[a + 1][b + 1] == 0) {
                        teamchance[i] = 60;
                        bestmoveindex[i][0] = a + 1;
                        bestmoveindex[i][1] = b + 1;
                    }
                }
            }
            else if (deskinfo[a][b] == 3) {
                ach = a;
                bch = b;
                //Диагональ 1 на ввниз
                for (chdiag = 0; chdiag < 7; chdiag++) {
                    ach++;
                    bch++;
                    if (ach > 7 || bch > 7) {
                        break;
                    }
                    if (deskinfo[ach][bch] == 1 || deskinfo[ach][bch] == 3) {
                        break;
                    }
                    if (deskinfo[ach - 1][bch - 1] == 0 && deskinfo[ach - 1][bch - 1] == 0) {
                        diag1mov[chdiag][0] = 25;
                        diag1mov[chdiag][1] = ((ach + 1) * 10) + (bch + 1);
                    }
                    //ход с встречей с врагом но с защитой от смертьи
                    else if ((deskinfo[ach - 1][bch - 1] == 2 && deskinfo[ach + 1][bch + 1] == 1 && deskinfo[ach - 1][bch + 1] == 0) || (deskinfo[ach - 1][bch + 1] == 2 && deskinfo[ach + 1][bch - 1] == 1 && deskinfo[ach - 1][bch - 1] == 0)) {
                        diag1mov[chdiag][0] = 35;
                        diag1mov[chdiag][1] = ((ach + 1) * 10) + (bch + 1);
                    }

                    //ход с встречей с врагом но без защиты
                    else if ((deskinfo[ach - 1][bch - 1] == 2 && deskinfo[ach + 1][bch + 1] == 0 && deskinfo[ach - 1][bch + 1] == 0) || (deskinfo[ach - 1][bch - 1] == 2 && deskinfo[ach - 1][bch - 1] == 2 && (deskinfo[ach + 1][bch - 1] == 0 || deskinfo[ach + 1][bch + 1] == 0))) {
                        diag1mov[chdiag][0] = 15;
                        diag1mov[chdiag][1] = ((ach + 1) * 10) + (bch + 1);
                    }
 
                    //ход на убийство
                    else if (deskinfo[ach][bch] == 2 || deskinfo[ach][bch] == 4) {
                        if (deskinfo[ach + 1][bch + 1] == 0) {
                            diag1mov[chdiag][0] = 90;
                            diag1mov[chdiag][1] = ((ach + 1 + 1) * 10) + (bch + 1);
                        }
                    }
 
                    //ход к стене
                    else if (bch == 7) {
                        if (deskinfo[ach][bch] == 0) {
                            diag1mov[chdiag][0] = 60;
                            diag1mov[chdiag][1] = ((ach + 1) * 10) + (bch + 1);
                        }
                    }
                    // ход к нижней границе
                    else if (ach == 7) {
                        if (deskinfo[ach][bch] == 0) {
                            diag1mov[chdiag][0] = 60;
                            diag1mov[chdiag][1] = ((ach + 1) * 10) + (bch + 1);
                        }
                    }
                }
 
                safech = chdiag;
                ach = a;
                bch = b;
                //Диагональ 1 вверх
                for (chdiag = safech; chdiag < 7; chdiag++) {
                    ach--;
                    bch--;
                    if (ach < 0 || bch < 0) {
                        break;
                    }
                    if (deskinfo[ach][bch] == 1 || deskinfo[ach][bch] == 3) {
                        break;
                    }
 
                    if (deskinfo[ach - 1][bch - 1] == 0 && deskinfo[ach - 1][bch - 1] == 0) {
                        diag1mov[chdiag][0] = 25;
                        diag1mov[chdiag][1] = ((ach + 1) * 10) + (bch + 1);
                    }
 
                    //ход с встречей с врагом но с защитой от смертьи
                    else if ((deskinfo[ach - 1][bch - 1] == 2 && deskinfo[ach + 1][bch + 1] == 1 && deskinfo[ach - 1][bch + 1] == 0) || (deskinfo[ach - 1][bch + 1] == 2 && deskinfo[ach + 1][bch - 1] == 1 && deskinfo[ach - 1][bch - 1] == 0)) {
                        diag1mov[chdiag][0] = 35;
                        diag1mov[chdiag][1] = ((ach + 1) * 10) + (bch + 1);
                    }
 
                    //ход с встречей с врагом но без защиты
                    else if ((deskinfo[ach - 1][bch - 1] == 2 && deskinfo[ach + 1][bch + 1] == 0 && deskinfo[ach - 1][bch + 1] == 0) || (deskinfo[ach - 1][bch - 1] == 2 && deskinfo[ach - 1][bch - 1] == 2 && (deskinfo[ach + 1][bch - 1] == 0 || deskinfo[ach + 1][bch + 1] == 0))) {
                        diag1mov[chdiag][0] = 15;
                        diag1mov[chdiag][1] = ((ach + 1) * 10) + (bch + 1);
                    }
 
                    //ход на убийство
                    else if (deskinfo[ach][bch] == 2 || deskinfo[ach][bch] == 4) {
                        if (deskinfo[ach - 1][bch - 1] == 0) {
                            diag1mov[chdiag][0] = 90;
                            diag1mov[chdiag][1] = ((ach) * 10) + (bch);
                        }
                    }
 
                    //ход к стене
                    else if (bch == 0) {
                        if (deskinfo[ach][bch] == 0) {
                            diag1mov[chdiag][0] = 60;
                            diag1mov[chdiag][1] = ((ach + 1) * 10) + (bch + 1);
                        }
                    }
 
                    else if (ach == 0) {
                        if (deskinfo[ach][bch] == 0) {
                            diag1mov[chdiag][0] = 60;
                            diag1mov[chdiag][1] = ((ach + 1) * 10) + (bch + 1);
                        }
                    }
                }

                ach = a;
                bch = b;
 
                //Диагональ 2 ввниз
                for (chdiag = 0; chdiag < 7; chdiag++) {
                    ach++;
                    bch--;
                    if (ach > 7 || bch < 0) {
                        break;
                    }
                    if (deskinfo[ach][bch] == 1 || deskinfo[ach][bch] == 3) {
                        break;
                    }
                    if (deskinfo[ach - 1][bch - 1] == 0 && deskinfo[ach - 1][bch - 1] == 0) {
                        diag1mov[chdiag][0] = 25;
                        diag1mov[chdiag][1] = ((ach + 1) * 10) + (bch + 1);
                    }
                    //ход с встречей с врагом но с защитой от смертьи
                    else if ((deskinfo[ach - 1][bch - 1] == 2 && deskinfo[ach + 1][bch + 1] == 1 && deskinfo[ach - 1][bch + 1] == 0) || (deskinfo[ach - 1][bch + 1] == 2 && deskinfo[ach + 1][bch - 1] == 1 && deskinfo[ach - 1][bch - 1] == 0)) {
                        diag1mov[chdiag][0] = 35;
                        diag1mov[chdiag][1] = ((ach + 1) * 10) + (bch + 1);
                    }
 
                    //ход с встречей с врагом но без защиты
                    else if ((deskinfo[ach - 1][bch - 1] == 2 && deskinfo[ach + 1][bch + 1] == 0 && deskinfo[ach - 1][bch + 1] == 0) || (deskinfo[ach - 1][bch - 1] == 2 && deskinfo[ach - 1][bch - 1] == 2 && (deskinfo[ach + 1][bch - 1] == 0 || deskinfo[ach + 1][bch + 1] == 0))) {
                        diag1mov[chdiag][0] = 15;
                        diag1mov[chdiag][1] = ((ach + 1) * 10) + (bch + 1);
                    }
 
                    //ход на убийство
                    else if (deskinfo[ach][bch] == 2 || deskinfo[ach][bch] == 4) {
                        if (deskinfo[ach + 1][bch - 1] == 0) {
                            diag1mov[chdiag][0] = 90;
                            diag1mov[chdiag][1] = ((ach + 1 + 1) * 10) + (bch);
                        }
                    }
 
                    //ход к стене
                    else if (bch == 0) {
                        if (deskinfo[ach][bch] == 0) {
                            diag1mov[chdiag][0] = 60;
                            diag1mov[chdiag][1] = ((ach + 1) * 10) + (bch + 1);
                        }
                    }
 
                    // ход к нижней границе
                    else if (ach == 7) {
                        if (deskinfo[ach][bch] == 0) {
                            diag1mov[chdiag][0] = 60;
                            diag1mov[chdiag][1] = ((ach + 1) * 10) + (bch + 1);
                        }
                    }
                }
 
                safech = chdiag;
                ach = a;
                bch = b;
                
                //Диагональ 2 вверх
                for (chdiag = safech; chdiag < 7; chdiag++) {
                    ach--;
                    bch++;
                    if (ach < 0 || bch > 7) {
                        break;
                    }
                    if (deskinfo[ach][bch] == 1 || deskinfo[ach][bch] == 3) {
                        break;
                    }
                    if (deskinfo[ach - 1][bch - 1] == 0 && deskinfo[ach - 1][bch - 1] == 0) {
                        diag1mov[chdiag][0] = 25;
                        diag1mov[chdiag][1] = ((ach + 1) * 10) + (bch + 1);
                    }
                    //ход с встречей с врагом но с защитой от смертьи
                    else if ((deskinfo[ach - 1][bch - 1] == 2 && deskinfo[ach + 1][bch + 1] == 1 && deskinfo[ach - 1][bch + 1] == 0) || (deskinfo[ach - 1][bch + 1] == 2 && deskinfo[ach + 1][bch - 1] == 1 && deskinfo[ach - 1][bch - 1] == 0)) {
                        diag1mov[chdiag][0] = 35;
                        diag1mov[chdiag][1] = ((ach + 1) * 10) + (bch + 1);
                    }
 
                    //ход с встречей с врагом но без защиты
                    else if ((deskinfo[ach - 1][bch - 1] == 2 && deskinfo[ach + 1][bch + 1] == 0 && deskinfo[ach - 1][bch + 1] == 0) || (deskinfo[ach - 1][bch - 1] == 2 && deskinfo[ach - 1][bch - 1] == 2 && (deskinfo[ach + 1][bch - 1] == 0 || deskinfo[ach + 1][bch + 1] == 0))) {
                        diag1mov[chdiag][0] = 15;
                        diag1mov[chdiag][1] = ((ach + 1) * 10) + (bch + 1);
                    }
 
                    //ход на убийство
                    else if (deskinfo[ach][bch] == 2 || deskinfo[ach][bch] == 4) {
                        if (deskinfo[ach + 1][bch - 1] == 0) {
                            diag1mov[chdiag][0] = 90;
                            diag1mov[chdiag][1] = ((ach) * 10) + (bch + 2);
                        }
                    }
 
                    //ход к стене
                    else if (bch == 7) {
                        if (deskinfo[ach][bch] == 0) {
                            diag1mov[chdiag][0] = 60;
                            diag1mov[chdiag][1] = ((ach + 1) * 10) + (bch + 1);
                        }
                    }
 
                    else if (ach == 0) {
                        if (deskinfo[ach][bch] == 0) {
                            diag1mov[chdiag][0] = 60;
                            diag1mov[chdiag][1] = ((ach + 1) * 10) + (bch + 1);
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
            }
        }
        inaafter = bestmoveto[0];
        inbafter = bestmoveto[1];
        inabefore = whitech[i][0];
        inbbefore = whitech[i][1];
        if (deskinfo[inaafter - 1][inbafter - 1] == 2 || deskinfo[inaafter - 1][inbafter - 1] == 4) {
            deskinfo[inaafter - 1][inbafter - 1] == 0;
        }
        if (deskinfo[inabefore][inbbefore] == 3) {
            deskinfo[inaafter][inbafter] = 3;
        }
        else {
            deskinfo[inaafter][inbafter] = 1;
        }
        deskinfo[inabefore][inbbefore] = 0;
    }
}