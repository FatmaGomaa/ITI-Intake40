/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lab022;

/*
public class Lab022 {

   
    public static void main(String[] args) {
        // TODO code application logic here
        String s = "192.168.1.1";
        System.out.println(s);
        String[] arrOfStr = s.split("\\.");
        for (String a: arrOfStr){
            System.out.println(a);
        }
        
     StringTokenizer st = new StringTokenizer("192.168.1.1",".");
              System.out.println(s);

     while (st.hasMoreTokens()) {  
         System.out.println(st.nextToken());  
     }  
    }
    
}

*/

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
//package lab023;

/**
 *
 * @author FatmaGomaa
 */
 class Lab023 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {

        calc(args);

    }

    public static int calc(String[] numbers) {
        int i =0;
        int results = Integer.parseInt(numbers[0]);

        for (i = 1; i < numbers.length; i+=2) {

            switch (numbers[i].charAt(0)) {

                case '+':
                    results += Integer.parseInt(numbers[i+1]);
                    break;
                case '-':
                    results -= Integer.parseInt(numbers[i+1]);
                    break;
                case 'x':
                    results *= Integer.parseInt(numbers[i+1]);
                    break;
                case '/':
                    results /= Integer.parseInt(numbers[i+1]);
                    break;
            }
        }
        
        System.out.println("the result is: " + results);
        return results;
    }

}
