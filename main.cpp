#include <string>
#include <iostream>
#include <fstream>
struct node {

	std::string word;
	int count;
	node* next;
};
class UnorderedLinkedList
{
private:
	node* head = NULL;
	node* tail = NULL;
public:
	void insertNewWord(std::string word, int count) {
		node* temp = new node();
		temp->word = word;
		temp->count = count;
		temp->next = NULL;
		if (head == NULL)
		{
			head = temp;
			tail = temp;
			temp = NULL;
		}
		else {
			tail->next = temp;
			tail = temp;
		}
	}
	void incrementTheCount(int count,node* &activeNode) {
		activeNode->count += count;
	}
	void addUnigram(std::string word,int count) {
		node* temp = head;
		bool exists = false;
		while (temp != NULL) {
			if (temp->word == word) {

				exists = true;

				incrementTheCount(count,temp);

			}
			temp = temp->next;
		}
		if (!exists)
		{
			insertNewWord(word, count);
		}
	}
};

int main()
{
	std::ifstream ourData;
	UnorderedLinkedList myList;
    int nthChar = 0;


	ourData.open("PublicationsDataSet.txt");
    int i = 0;
	char counter;
    std::string keyWord = "unigramCount";


        while(!ourData.eof()) {

            bool matches = true;
            for (int j = 0; j < keyWord.size(); ++j) {
                ourData >> counter;
                if (counter != keyWord[j]) {
                    matches = false;
                }
            }
            ourData >> counter >> counter;//skipping the first quotation mark
            if (matches) {
                for (int j = 0; j < 10; ++j) {
                    std::cout << counter << " ";
                    ourData >> counter;
                }
                break;
            }
        }
	ourData.close();

}
