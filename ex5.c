TVShow *findShow(char *name) {
    // 1. הגנה מפני גישה למערך ריק
    if (database == NULL || dbSize == 0) {
        return NULL;
    }

    // 2. ריצה על המערך הדו-ממדי
    for (int i = 0; i < dbSize; i++) {
        for (int j = 0; j < dbSize; j++) {
            // 3. בדיקה שהתא אינו NULL לפני גישה לשם
            if (database[i][j] != NULL) {
                if (strcmp(database[i][j]->name, name) == 0) {
                    return database[i][j];
                }
            }
        }
