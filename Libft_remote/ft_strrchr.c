/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/20 12:49:49 by lhop          #+#    #+#                 */
/*   Updated: 2022/10/20 13:10:50 by lhop          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

char ft_strrchr(const char *book, int letter)
{
    int i;
    i = 0;
    char* occurance;
    int checksrch;
    checksrch = 0;
    int book_len;
    book_len = ft_strlen(book);

    while (i < book_len + 1)
    {
        if (book[i] == letter)
        {
            occurance = (char*)book+i;
            checksrch++;
        }
        i++;
    }

    if (checksrch > 0)
    {
        return((char*)occurance);
    }
    else
    {
        return (NULL);
    }
}

/*
ft_strrchr: we are trying to find a char in a string, and return the
last occurance of it in the string. 

1: I make an index for moving through the source.

2: I make container for the return data when an occurance is found.

3: I make a checker for whether an occurance has appeared.

4: I find the length of the source.

5: I create a while loop on the condition the index is under its total
length, plus one, because I want the "\0" char to be included.

6: I check with 'if', if the current place is the same as the search query.

7: when it is, I store its plce in the occurance placeholder.

8: I then check that the occurance has happened. 

9: When the whileloop has moved through the entire source, I check if the 
occurance ticker is more than 0. This means the query was found at some point.

10: I then return the data stored in the occurance placeholder. 
This will always be the last occurance. 

11: If there have been no occurances, I return 'NULL'.

12: kthx.
*/