bool checkStraightLine(int** coordinates, int coordinatesSize, int* coordinatesColSize) {
    int i, j;
    if(coordinatesSize==1) {
        return false;
    }
    if(coordinatesSize==2) {
        return true;
    }
    int x0 = *(*(coordinates+0)+0);
    int y0 = *(*(coordinates+0)+1);
    int x1 = *(*(coordinates+1)+0);
    int y1 = *(*(coordinates+1)+1);
    float dx = x1 - x0;
    float dy = y1 - y0; 

    for(i=2;i<coordinatesSize;i++) {

        int x = coordinates[i][0];
        int y = coordinates[i][1];
        if(( ( dx*(y-y0) ) != ( dy*(x-x0) ) )) {
            return false;
        }
    }






    return true;
}