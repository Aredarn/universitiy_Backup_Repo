/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author L5C0T6
 */
public class Etel {
    private String nev;
    private int ar;
    
    public Etel(String nev) {
        this.nev = nev;
        
        if(nev.equals("Rantott hus"))
            ar = 3000;
        else if(nev.equals("Sult krumpli"))
            ar = 2000;
        else if(nev.equals("Porkolt"))
            ar = 1000;
    }

    public String getNev() {
        return nev;
    }

    public int getAr() {
        return ar;
    }
    
    

}
