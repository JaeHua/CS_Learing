void rlease(LinkNode *& L)
{
	if(L!=NULL)
	{
		release(L->next);
		free(L);
	}
} 
