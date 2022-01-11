#include "LinkedList.cpp"
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

	ourData.open("PublicationsDataSet.txt");
	std::string singleText;
	ourData >> singleText;
	std::cout << singleText << std::endl;
	ourData.close();
	
	
}

