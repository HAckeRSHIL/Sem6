import java.net.*; 
import java.io.*;
import java.math.BigInteger; 
  
public class Mathrealserver 
{ 
    public Mathrealserver(int port) 
    { 
    		Socket          soc   = null; 
    	    ServerSocket    ss   = null;  
    	    try {
				ss = new ServerSocket(port);
			} catch (IOException e) {
				// TODO Auto-generated catch block
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
			        String line = ""; 
			        String ans=new String();
			        line = (String)dis.readUTF(); 
			        String[] test=line.split("#"); 
			        String str=test[0];
			        if(str.isEmpty())
					        	ans="Enter Text First";
					else
					{
							int data=Integer.parseInt(str);
							if(test[1].equals("1"))
							{
								int flag=0;
								for(int i=2;i<data/2;i++)
								{
									if(data%i==0)
									{
										flag=1;
										ans=data+" is not Prime.";
										break;
									}
								}
								if(flag==0)
								{
									ans=data+" is Prime.";
								}
							}
							else if(test[1].equals("2"))
							{
								
								int len=str.length();
								int f=0;
								for(int i=0;i<len/2;i++)
								{
									if(str.charAt(i)!=str.charAt(--len))
										{
											f=1;
											ans=str+" is not Palidrome.";
											break;
										}
								}
								if( f==0)
									ans=str+" is Palidrome.";
							}
							
							else if(test[1].equals("3"))
							{
								 BigInteger f = new BigInteger("1");
							        for (int i = 2; i <= data; i++) 
							            f = f.multiply(BigInteger.valueOf(i)); 
							        String str1 = f.toString(); 
								ans=str1;
							}
							else if(test[1].equals("4"))
							{
								
								String ans2;
								ans2="0 1 ";
								int a=0,b=1,temp;
								for(int i=0;i<data-2;i++)
								{
									temp=a+b;
									a=b;
									b=temp;
									ans2=ans2+Integer.toString(b)+" "/*Integer.toString(b)*/ ;
			    					}
			    					ans=ans2;
			    				}
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
        Mathrealserver server = new Mathrealserver(8004); 
    } 
}