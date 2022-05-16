/********************************
    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

********************************/

Node* middle_(Node* &head) {
	Node* slow = head;
	Node* fast = slow;

	while (fast->next!=head) {
		fast = fast->next;
		if (fast!=head && fast->next!=head) {
			fast = fast->next;
			slow = slow->next;
		}
		if (fast==head)
			break;
	}
	return slow;
}

void splitCircularList(Node *head)
{
    // Write your code here.
	Node* head2 = middle_(head)->next;
	middle_(head)->next = head;
	Node* temp = head2;
	while(temp->next != head)
		temp = temp->next;
	temp->next = head2;
}
