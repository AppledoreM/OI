import java.io.*;
import java.util.*;

public class KMP{
    public static int[] prev;
    public static int[] computeLPS(char[] s){
        int[] lps = new int[s.length];
        for(int i = 1; i < s.length; ++i){
            int j = lps[i - 1];
            while(j > 0 && s[i] != s[j]){
                j = lps[j - 1];
            }
            if(s[i] == s[j]){
                ++j;
            }
            lps[i] = j;
        }
        return lps;
    }
    public static void print(int[] arr){
        for(int ele : arr){
            System.out.print(ele + "\t");
        }
        System.out.println();
    }
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        char[] txt = in.nextLine().toCharArray(), pat = in.nextLine().toCharArray();
        int[] lps = computeLPS(pat);
        int i = 0, j = 0;
        while(i < txt.length){
            if(txt[i] == pat[j]){
                ++i;
                ++j;
            }
            //matches
            if(j == pat.length){
                j = lps[j - 1];
            }
            else if(i < txt.length && txt[i] != pat[j]){
                if(j != 0){
                    j = lps[j - 1];
                }
                else{
                    ++i;
                }
            }
        }
        
    }
}