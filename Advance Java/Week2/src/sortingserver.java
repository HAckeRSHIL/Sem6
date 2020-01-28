import java.net.*; 
import java.io.*;
  
public class sortingserver
{ 
    public sortingserver(int port) 
    { 
    		Socket          soc   = null; 
    	    ServerSocket    ss   = null;   
    	    try 
    	    {
				ss = new ServerSocket(port);
			} 
    	    catch (IOException e) 
    	    {
				e.printStackTrace();
			} 
            
    	    System.out.println("Server started"); 
            System.out.println("Waiting for a client ..."); 
    	    while(true)
    	    {
    	    	try
    	    	{ 
            
  
		            soc = ss.accept(); 
		            System.out.println("Client accepted"); 
		    		DataInputStream dis = new DataInputStream(soc.getInputStream());
					DataOutputStream dout = new DataOutputStream(soc.getOutputStream());
					
				//	String s1=(String)dis.readUTF();            // takes input from the client socket 
					//System.out.println(s1);
		
		            String line = ""; 
		            String ans=new String();          
		            line = (String)dis.readUTF(); 
		            String[] test=line.split(" ");
		            if(line.isEmpty())
		    		{
		                 ans="Enter Text First";
		    		}
		    		else
		    		{
		    			int len=test.length;
		    			int[] arr=new int[len];
		    			for(int i=0;i<len;i++)
		    			{
		    				arr[i]=Integer.parseInt(test[i]);
		    				
		    			}
		    			for(int i=0;i<len-1;i++)
		    			{
		    				for(int j=0;j<len-i-1;j++)
		    				{
		    					if(arr[j]>arr[j+1])
		    					{
		    						int temp = arr[j];
		    	                    arr[j] = arr[j+1];
		    	                    arr[j+1] = temp;
		    					}
		    				}
		    			}
		    			for(int i=0;i<len;i++)
		    				ans=ans+Integer.toString(arr[i])+" ";	
		    		}
		            dout.writeUTF(ans);
		            dout.flush(); 
        } 
        catch(IOException i) 
        { 
            System.out.println(i); 
        }
       }
    } 
  
    public static void main(String args[]) 
    { 
        sortingserver server = new sortingserver(8004); 
    } 
}