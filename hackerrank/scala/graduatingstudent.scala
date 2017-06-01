object Solution {

    def main(args: Array[String]) {
        val sc = new java.util.Scanner (System.in);
        var n = sc.nextInt();
        var unit = 0;
        var rounded = 0;
        var modified = 0;
        var grades = new Array[Int](n);
        for(grades_i <- 0 to n-1) {
           grades(grades_i) = sc.nextInt();
        }
        
        for(i <- 0 to n-1){
            if(grades(i) < 38){
                System.out.println(grades(i));
            } else {
                unit = grades(i) % 10;
                rounded = if(unit < 5) grades(i) + (5-unit) else grades(i) + (10-unit);
                modified = rounded - grades(i);
                if(modified < 3){
                    System.out.println(rounded);
                } else {
                    System.out.println(grades(i));
                }
                
            }
        }
    }
}
