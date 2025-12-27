void deleteEpisode(){
    printf("Enter the name of the show:\n");
    char *showName = getString();
    TVShow *show = findShow(showName);
    if(!show){
        printf("Show not found.\n");
        free(showName);
        return;
    }
    printf("Enter the name of the season:\n");
    char *seasonName = getString();
    Season *season = findSeason(show, seasonName);
    if(!season){
        printf("Season not found.\n");
        free(showName);
        free(seasonName);
        return;
    }
    printf("Enter the name of the episode:\n");
    char *episodeName = getString();
    Episode *episode = findEpisode(season, episodeName);
    if(!episode){
        printf("Episode not found.\n");
        free(showName);
        free(seasonName);
        free(episodeName);
        return;
    }

    free(showName);
    free(seasonName);
    Episode *curr = season->episodes;
    Episode *prev = NULL;

    while (curr != NULL && strcmp(curr->name, episodeName) != 0) {
        prev = curr;
        curr = curr->next;
    }
    free(episodeName);

    if (curr == NULL) {
        printf("Episode not found.\n");
        return;
    }
    if (prev == NULL) {
        season->episodes = curr->next;
    } else {
        prev->next = curr->next;
    }
    free(curr->name);
    free(curr->length);
    free(curr);
}


void printMenuSub() {
    int choice;
    printf("Choose an option:\n");
    printf("1. Print a TV show\n");
    printf("2. Print an episode\n");
    printf("3. Print the array\n");
    scanf("%d", &choice);
    getchar();
    switch (choice) {
        case 1: printShow(); break;
        case 2: printEpisode(); break;
        case 3: printArray(); break;
    }
}
