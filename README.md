ft_p_projt
==========

this a server /client exercise 

struct sockaddr_in {
   uint8_t         sin_len;       /* longueur totale      */
   sa_family_t     sin_family;    /* famille : AF_INET     */
   in_port_t       sin_port;      /* le numéro de port    */
   struct in_addr  sin_addr;      /* l'adresse internet   */
   unsigned char   sin_zero[8];   /* un champ de 8 zéros  */
}

struct sockaddr {
   unsigned char   sa_len;         /* longueur totale 		*/
   sa_family_t     sa_family;      /* famille d'adresse 	*/
   char            sa_data[14];    /* valeur de l'adresse	*/
};

  struct  protoent 
  {
       char    *p_name;        /* official name of protocol */
       char    **p_aliases;    /* alias list */
       int     p_proto;        /* protocol number */
  };