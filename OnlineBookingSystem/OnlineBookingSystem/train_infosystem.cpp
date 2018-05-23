#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "train_info.h"
#include "order_info.h"

void input_train_info()
{
	FILE *fp;
	char str0, *str_link = "|", *str_enter = "\n", train_num[10], train_route[100], train_node[100], train_info[1000];
	TNODE tnode_start;
	int i;
	if (!fopen_s(&fp, "traininfo.txt", "a+"))
	{
		printf("�Ƿ�������복����Ϣ�����������롮#�������������롮/����\n");
		_flushall();
		while (getchar() != '#')
		{
			_flushall();
			printf("�����복�Σ�");
			gets_s(train_num);
			strcpy_s(train_info, train_num);
			strcat_s(train_info, sizeof(train_info), str_link);
			//����ô��г�ĳ����·��Ϣ
			printf("�Ƿ��������ó��ξ���վ��Ϣ�����������롮#�������������롮/����\n");
			while (getchar() != '#')
			{
				_flushall();
				printf("�����복��վ��ϸ��Ϣ��\n");
				printf("�����ʽΪ����ǰվ ����ʱ�� �뿪ʱ�� ͣ��ʱ�� ��վ����һվ��ʱ��@��λ����@��λ�۸�@����λ����ԭ������λ@����λ������Ʊ��@��\n");
				printf("���磺������ 1 2 3 60@1@100@50@14@2@120@50@25@��\n");
				printf("��ע�������������ĸ�ʽ���뵱ǰվ�Ķ�����λ���͵���λ��Ϣ\n");
				gets_s(train_node);
				strcat_s(train_info, sizeof(train_info), train_node);
				strcat_s(train_info, sizeof(train_info), str_link);
				_flushall();
				printf("�Ƿ��������ó��ξ���վ��Ϣ�����������롮#�������������롮/����\n");
			}
			strcat_s(train_info, sizeof(train_info), str_enter);
			fprintf(fp, "%s", train_info);
			_flushall();
			printf("�Ƿ�������복����Ϣ�����������롮#�������������롮/����\n");
		}
	}
	fclose(fp);

}

void input_traininfo_fast()
{
	//���ɲ���������ļ�
	FILE * fp1;
	char str1;
	if (fopen_s(&fp1, "testfile.txt", "w"))
	{
		printf("file cannot be opened\n");
		exit(1);
	}
	printf("��������һ�����ε�������Ϣ��\n");
	printf("�����ʽΪ������|��ǰվ ����ʱ�� �뿪ʱ�� ͣ��ʱ�� ��վ����һվ��ʱ��@��λ����@��λ�۸�@����λ����ԭ������λ@����λ������Ʊ��@...|��ǰվ...@|��\n");
	printf("���磺��G1|���� 1 2 3 60@1@100@50@14@2@120@50@25@|���� 2 3 4 60@1@20@30@10@|��\n");
	printf("��ע�������������ĸ�ʽ����������վ�Լ���ǰվ�Ķ�����λ���͵���λ��Ϣ\n");
	while ((str1 = fgetc(stdin)) != '#')
		fputc(str1, fp1);
	fclose(fp1);
}

void read_traininfo(TINFO *tinfo)
{
	FILE *fp;
	TNODE *p, *ptemp;
	TINFO *t, *ttemp = tinfo;
	SEAT *q, *qtemp;
	int i = 0, m = 0, n = 0, len;
	char str, str0, buf[MAX_LINE], tnum[10];
	if (fopen_s(&fp, "traininfo.txt", "r"))
	{
		printf("file cannot be opened\n");
		exit(1);
	}
	while (fgets(buf, MAX_LINE, fp) != NULL)
	{
		i = 0;
		len = strlen(buf);
		buf[len - 1] = '\0';  /*ȥ�����з�*/
		//printf("%s %d \n", buf, len - 1);
		Init_tinfo(t);
		n = 0;
		while (1)
		{
			if (buf[i] == '|')
			{
				t->train_num[n] = '\0';
				tnum[n] = '\0';
				i++;
				break;
			}
			t->train_num[n] = buf[i];
			tnum[n] = buf[i];
			n++;
			i++;
		}
		ptemp = t->tnode;
		while (i < strlen(buf))
		{
			m = 0;
			Init_tnode(p);
			strcpy_s(p->train_num, sizeof(tnum), tnum);
			switch (m)
			{
			case 0:
			{
					  int n = 0;
					  while (1)
					  {
						  if (buf[i] == ' ')
						  {
							  p->current_station[n] = '\0';
							  i++;
							  break;
						  }
						  p->current_station[n] = buf[i];
						  n++;
						  i++;
					  }
					  m++;
			}
			case 1:
			{
					  int n = 0;
					  while (1)
					  {

						  if (buf[i] == ' ')
						  {
							  p->arrive_time[n] = '\0';
							  i++;
							  break;
						  }
						  p->arrive_time[n] = buf[i];
						  n++;
						  i++;
					  }
					  m++;

			}
			case 2:
			{
					  int n = 0;
					  while (1)
					  {

						  if (buf[i] == ' ')
						  {
							  p->leave_time[n] = '\0';
							  i++;
							  break;
						  }
						  p->leave_time[n] = buf[i];
						  n++;
						  i++;
					  }
					  m++;
			}
			case 3:
			{
					  int n = 0;
					  while (1)
					  {

						  if (buf[i] == ' ')
						  {
							  p->stay_time[n] = '\0';
							  i++;
							  break;
						  }
						  p->stay_time[n] = buf[i];
						  n++;
						  i++;
					  }
					  m++;
			}
			case 4:
			{
					  int n = 0;
					  while (1)
					  {

						  if (buf[i] == '@')
						  {
							  p->last_time[n] = '\0';
							  break;
						  }
						  p->last_time[n] = buf[i];
						  n++;
						  i++;
					  }
					  m++;
			}
			case 5:
			{
					  qtemp = p->seat;
					  while (buf[i] == '@'&&buf[i + 1] != '|')
					  {
						  i++;
						  Init_seat(q);
						  n = 0;
						  while (1)
						  {
							  if (buf[i] == '@')
							  {
								  q->seat_type[n] = '\0';
								  i++;
								  break;
							  }
							  q->seat_type[n] = buf[i];
							  n++;
							  i++;
						  }
						  n = 0;
						  while (1)
						  {
							  if (buf[i] == '@')
							  {
								  q->seat_price[n] = '\0';
								  i++;
								  break;
							  }
							  q->seat_price[n] = buf[i];
							  n++;
							  i++;
						  }
						  n = 0;
						  while (1)
						  {
							  if (buf[i] == '@')
							  {
								  q->ticket_total[n] = '\0';
								  i++;
								  break;
							  }
							  q->ticket_total[n] = buf[i];
							  n++;
							  i++;
						  }
						  n = 0;
						  while (1)
						  {
							  if (buf[i] == '@')
							  {
								  q->ticket_left[n] = '\0';
								  break;
							  }
							  q->ticket_left[n] = buf[i];
							  n++;
							  i++;
						  }
						  q->next = qtemp->next;
						  qtemp->next = q;
						  qtemp = qtemp->next;
					  }
					  qtemp = NULL;

			}
				//printf("%s,%s,%s", p->seat->next->next->seat_type, p->seat->next->next->seat_price, p->seat->next->next->ticket_left);
				p->next = ptemp->next;
				ptemp->next = p;
				ptemp = ptemp->next;
				i += 2;
			}
		}
		ptemp = NULL;
		t->next = ttemp->next;
		ttemp->next = t;
		ttemp = ttemp->next;
	}
	ttemp = NULL;
	//printf("%s,%s,%s", tinfo->next->tnode->next->current_station, tinfo->next->next->train_num, tinfo->next->next->tnode->next->seat->next->seat_type);
	fclose(fp);


}

Status Locate_train_route(TINFO *head, QUEUE &Q, char *key_s, char *key_d)
{
	TINFO *p = head;
	TNODE *q = p->tnode->next, *temp = NULL;
	int f = 0;
	while (q)
	{
		if ((strcmp(key_d, q->current_station) == 0) && (temp != NULL) && (strcmp(key_s, temp->current_station) == 0))
		{
			EnQueue(Q, q);
			f = 0;
		}
		if (f == 1)
			EnQueue(Q, q);
		if (strcmp(key_s, q->current_station) == 0)
		{
			EnQueue(Q, q);
			f = 1;
		}
		if (!QueueEmpty(Q))
			GetFront(Q, temp);

		q = q->next;
	}
	if (f == 1 && !(QueueEmpty(Q)))
	{
		if (EmptyQueue(Q))
			return OK;
		else
			return ERROR;
	}
	return OK;
}

int *is_ticket(TNODE *tnode)
{
	SEAT *s;
	int temp, stype, left_ticket[10][2] = { 0 }, i = 0, count = 0, f = 0, *t;
	static int ticket_type[10] = { 0 };
	t = ticket_type;
	TNODE *q = tnode;
	QUEUE Q;
	InitQueue(Q);
	s = q->seat;
	s = s->next;
	while (q)
	{
		while (s)
		{
			//����һ�����У�����һ�����У������Ʊ�Ƿ񶼹������Ļ����������
			temp = atoi(s->ticket_left);
			stype = atoi(s->seat_type);
			if (left_ticket[stype][0] == 0)
			{
				left_ticket[stype][0] = temp;
				left_ticket[stype][1]++;
			}

			else if (temp < left_ticket[stype][0] && temp >= 0)
			{
				left_ticket[stype][0] = temp;
				left_ticket[stype][1]++;
			}
			else
				left_ticket[stype][1]++;
			s = s->next;
		}
		count++;
		EnQueue(Q, q);
		q = q->next;
		if (q)
			s = q->seat->next;
	}
	printf(";��վ��\n");
	do
	{
		if (DeQueue(Q, q))
			puts(q->current_station);
		else
			break;

	} while (q);
	printf("ʣ��Ʊ(��λ����--��Ʊ����)��\n");
	for (stype = 1; stype <= 10; stype++)
	{
		if (left_ticket[stype])
		{
			if (left_ticket[stype][0] > 0 && left_ticket[stype][1] == count)
			{
				ticket_type[i++] = stype;
				f = 1;
				printf("%d--%d\n", stype, left_ticket[stype][0]);
			}

		}
		else continue;

	}
	if (!f)
		printf("û��ʣ��Ʊ��\n");
	return t;

}

QUEUE search_traininfo(TINFO *tinfo)
{
	QUEUE Q, Q1, result;
	TINFO *p, t;
	TNODE *q, *temp;
	SEAT *s;
	char key[10], key_s[10], key_d[10], str;
	int left_ticket[10][1] = { 0 }, i = 0, j = 0, stype, iszero = 0, m, *ticket_type;
	InitQueue(result);
	printf("\n��ѯ��ʽ��\n1--���ճ��ν��в�ѯ\n2--����·�߽��в�ѯ\n������ѯ�����롮#��\n");
	while (1)
	{
		_flushall();
		printf("��ѡ���ѯ��ʽ��");
		scanf_s("%d", &m);
		switch (m)
		{
		case 1:
		{
				  //���ݳ��β�ѯ
				  //��������ĳ��Σ����в�ѯ����λ����������λ��ǰһ��
				  /*if (!QueueEmpty)
				  EmptyQueue(result);*/
				  _flushall();
				  printf("��������Ҫ��ѯ�ĳ��κţ�\n");
				  gets_s(key, sizeof(key));
				  p = Locate_train_num(tinfo, key);
				  // EnQueue(result, p->next->tnode->next);
				  if (p->next)
				  {
					  p = p->next;
					  q = p->tnode;
					  q = q->next;
					  is_ticket(q);

				  }
				  //������β����ڣ��˳���ѯ
				  else
					  printf("û�в�ѯ������Ϊ%s���г�\n", key);

				  break;

		}
		case 2:
		{
				  //����·�߲�ѯ
				  int count = 0;
				  /* if (!QueueEmpty)
				  EmptyQueue(result);*/
				  printf("������Ҫ��ѯ·�ߵ���㣺");
				  _flushall();
				  gets_s(key_s, sizeof(key_s));
				  printf("������Ҫ��ѯ·�ߵ��յ㣺");
				  _flushall();
				  gets_s(key_d, sizeof(key_d));
				  p = tinfo->next;
				  InitQueue(Q);
				  do
				  {
					  Locate_train_route(p, Q, key_s, key_d);
					  if (QueueEmpty(Q))
						  p = p->next;
					  else
					  {
						  count++;
						  printf("���κ�Ϊ��");
						  DeQueue(Q, q);
						  puts(q->train_num);
						  // while (!QueueEmpty(Q))
						  //{
						  // DeQueue(Q, q);
						  ticket_type = is_ticket(q);
						  if (*ticket_type>0)
						  {
							  EnQueue(result, q);
						  }
						  EmptyQueue(Q);
						  break;
						  //  }
						  p = p->next;

					  }

				  } while (p);
				  if (count)
					  printf("����ѯ��%d�����\n", count);
				  else
					  printf("δ��ѯ�������\n");
		}
		}
		printf("������ѯ�����롮#��,�����������������ѯ\n");
		if (getchar() == '#')
			break;

	}
	return result;

}

void write_traininfo(TINFO *&tinfo)
{
	FILE *fp;
	char str0, *str_link_t = "|", *str_enter = "\n", *str_link_c = " ", *str_link_s = "@", train_num[10], train_node[100], train_info[1000];
	TINFO *p = tinfo->next;
	TNODE *q;
	SEAT *s;
	if (fopen_s(&fp, "traininfo.txt", "w"))
	{
		printf("file cannot be opened\n");
		exit(1);
	}
	else
	{
		while (p)
		{
			strcpy_s(train_info, p->train_num);
			strcat_s(train_info, sizeof(train_info), str_link_t);
			//����ô��г�ĳ����·��Ϣ
			//G1|���� 1 2 3 60@1@100@50@25@2@120@50@25@|���� 2 3 4 60@1@20@30@15@|
			//��ǰվ ����ʱ�� �뿪ʱ�� ͣ��ʱ�� �Ӵ�վ����һվ����ʱ��
			//@��λ����@��λ�۸�@��Ʊ��@��Ʊ��
			q = p->tnode->next;
			while (q)
			{

				strcpy_s(train_node, sizeof(train_node), q->current_station);
				strcat_s(train_node, sizeof(train_node), str_link_c);
				strcat_s(train_node, sizeof(train_node), q->arrive_time);
				strcat_s(train_node, sizeof(train_node), str_link_c);
				strcat_s(train_node, sizeof(train_node), q->leave_time);
				strcat_s(train_node, sizeof(train_node), str_link_c);
				strcat_s(train_node, sizeof(train_node), q->stay_time);
				strcat_s(train_node, sizeof(train_node), str_link_c);
				strcat_s(train_node, sizeof(train_node), q->last_time);
				s = q->seat->next;
				strcat_s(train_node, sizeof(train_node), str_link_s);
				while (s)
				{
					strcat_s(train_node, sizeof(train_node), s->seat_type);
					strcat_s(train_node, sizeof(train_node), str_link_s);
					strcat_s(train_node, sizeof(train_node), s->seat_price);
					strcat_s(train_node, sizeof(train_node), str_link_s);
					strcat_s(train_node, sizeof(train_node), s->ticket_total);
					strcat_s(train_node, sizeof(train_node), str_link_s);
					strcat_s(train_node, sizeof(train_node), s->ticket_left);
					strcat_s(train_node, sizeof(train_node), str_link_s);
					s = s->next;
				}
				strcat_s(train_info, sizeof(train_info), train_node);
				strcat_s(train_info, sizeof(train_info), str_link_t);
				q = q->next;
			}
			strcat_s(train_info, sizeof(train_info), str_enter);
			fprintf(fp, "%s", train_info);
			p = p->next;
		}
	}
	fclose(fp);

}

void del_traininfo(TINFO *&tinfo)
{
	char key[10], train_num[10];
	TINFO *temp, *del;
	while (1)
	{
		printf("������Ҫɾ�����г����κţ�");
		_flushall();
		gets_s(key, sizeof(key));

		temp = Locate_train_num(tinfo, key);
		if (temp->next)
		{
			strcpy_s(train_num, sizeof(train_num), temp->next->train_num);
			if (ListDelete(temp, del))
			{
				write_traininfo(tinfo);
				printf("�г���Ϊ%s���г���¼ɾ���ɹ���\n", train_num);
			}
			else
				printf("�г���Ϊ%s���г���¼ɾ��ʧ�ܣ�\n", train_num);
		}
		else
			printf("δ���ҵ�Ŀ���г��ţ��������룡\n");
		printf("����ɾ�������롮#��,����ɾ�������롮/��\n");
		if (getchar() == '#')
			break;

	}
}

void read_all_traininfo(TINFO *tinfo)
{
	FILE *fp;
	char buf[MAX_LINE];
	int i, len;
	if (fopen_s(&fp, "traininfo.txt", "r"))
	{
		printf("file cannot be opened\n");
		exit(1);
	}
	while (fgets(buf, MAX_LINE, fp) != NULL)
	{
		i = 0;
		len = strlen(buf);
		buf[len - 1] = '\0';  /*ȥ�����з�*/
		printf("%s %d \n", buf, len - 1);
	}
	fclose(fp);
}

void book_ticket(TINFO *tinfo, OINFO *&oinfo)
{
	FILE *fp;
	OINFO *o;
	TNODE *temp, *p;
	QUEUE Q, Q1;
	SEAT *s;
	int t;
	char buf[MAX_LINE], orderinfo[1000], *str_link = "|", *str_enter = "\n", templine[2];
	int line = 0, len, *ticket_type, i = 0, isticket = 0, price = 0;
	Init_order(o);
	InitQueue(Q1);
	//��ȡorderinfo.txt�������ǰ�Ķ�����ţ��ر��ĵ�
	o->order_id[0] = '1';
	o->order_id[1] = '\0';
	if (fopen_s(&fp, "orderinfo.txt", "r"))
	{
		printf("file cannot be opened\n");
		//exit(1);
	}
	else
	{
		templine[0] = '0';
		while (fgets(buf, MAX_LINE, fp) != NULL)
			templine[0] = buf[0];
		line = atoi(templine);
		line++; //�½�������¼�ı��
		_itoa_s(line, o->order_id, 10);
		fclose(fp);
	}
	//�������û�ID���û���
	printf("�����������û�id��");
	_flushall();
	gets_s(o->passenger_id, sizeof(o->passenger_name));
	printf("�����������û�����");
	gets_s(o->passenger_name, sizeof(o->passenger_name));
	//���ݳ��λ�·�߶Գ�����Ʊ���в�ѯ
	printf("�������ʾ��Ϣ������Ʊ��ѯ��ע��ȷ�϶�Ʊ֮ǰ����ؽ��ж�·�ߵĲ�ѯ����");
	Q = search_traininfo(tinfo);
	printf("����������ȷ�����Σ�");
	_flushall();
	gets_s(o->train_num, sizeof(o->train_num));
	printf("����������ȷ����ʼվ��");
	_flushall();
	gets_s(o->station_s, sizeof(o->station_s));
	printf("����������ȷ���յ�վ��");
	_flushall();
	gets_s(o->station_d, sizeof(o->station_d));
	printf("��������λ���ࣺ");
	_flushall();
	gets_s(o->ticket_type, sizeof(o->ticket_type));
	if (QueueEmpty(Q))
		printf("�������룬�������վ���յ�վû����Ʊ��");
	while (!QueueEmpty(Q))
	{
		DeQueue(Q, temp);
		if (strcmp(temp->current_station, o->station_s) == 0 && strcmp(temp->train_num, o->train_num) == 0)
		{
			p = temp;
			while (strcmp(p->current_station, o->station_d) != 0)
			{
				EnQueue(Q1, p);
				p = p->next;
			}
			EnQueue(Q1, p);
			GetFront(Q1, p);
			ticket_type = is_ticket(p);
			int a, b;
			do
			{
				b = *(ticket_type + i);
				a = atoi(o->ticket_type);
				if (b == a)
				{
					//��Ʊ
					isticket = 1;
					break;
				}
				i++;

			} while (b > 0);
			if (isticket == 0)
			{
				//ûƱ����ʾ��Ϣ
				printf("�˴��г�����·����ʣ��Ʊ���������룡\n");
			}
			if (isticket == 1)
			{
				//ƴ����Ϣ��д���ĵ�,ͬʱ����Ϣ�ļ��ж�Ӧվ��Ʊ����1
				strcpy_s(orderinfo, sizeof(orderinfo), o->order_id);
				strcat_s(orderinfo, sizeof(orderinfo), str_link);
				o->state[0] = '1';
				o->state[1] = '\0';
				strcat_s(orderinfo, sizeof(orderinfo), o->state);
				strcat_s(orderinfo, sizeof(orderinfo), str_link);
				strcat_s(orderinfo, sizeof(orderinfo), o->passenger_id);
				strcat_s(orderinfo, sizeof(orderinfo), str_link);
				strcat_s(orderinfo, sizeof(orderinfo), o->passenger_name);
				strcat_s(orderinfo, sizeof(orderinfo), str_link);
				strcat_s(orderinfo, sizeof(orderinfo), o->train_num);
				strcat_s(orderinfo, sizeof(orderinfo), str_link);
				strcat_s(orderinfo, sizeof(orderinfo), o->station_s);
				strcat_s(orderinfo, sizeof(orderinfo), str_link);
				strcat_s(orderinfo, sizeof(orderinfo), o->station_d);
				strcat_s(orderinfo, sizeof(orderinfo), str_link);
				strcat_s(orderinfo, sizeof(orderinfo), o->ticket_type);
				strcat_s(orderinfo, sizeof(orderinfo), str_link);
				if (fopen_s(&fp, "orderinfo.txt", "a+"))
				{
					printf("file cannot be opened\n");
					//exit(1);
				}
				else
				{
					fprintf(fp, "%s", orderinfo);
					//GetFront(Q1, p);
					do
					{
						DeQueue(Q1, p);
						s = p->seat;
						while (s)
						{
							if (strcmp(o->ticket_type, s->seat_type) == 0)
							{
								t = atoi(s->ticket_left);
								t--;
								_itoa_s(t, s->ticket_left, 10);
								price += atoi(s->seat_price);
								break;
							}
							s = s->next;
						}
					} while (!QueueEmpty(Q1));
					_itoa_s(price, o->ticket_price, 10);
					strcpy_s(orderinfo, sizeof(orderinfo), o->ticket_price);
					strcat_s(orderinfo, sizeof(orderinfo), str_link);
					strcat_s(orderinfo, sizeof(orderinfo), str_enter);
					fprintf(fp, "%s", orderinfo);
					fclose(fp);
					write_traininfo(tinfo);
					printf("�ɹ���Ʊ��");
					printf("��Ʊ��ϢΪ���������-�û�id-�û���-��ʼվ-�յ�վ-��Ʊ����-��Ʊ�۸񣩣�%s-%s-%s-%s-%s-%s-%s\n", o->order_id, o->passenger_id, o->passenger_name, o->station_s, o->station_d, o->ticket_type, o->ticket_price);
				}
			}
		}

	}


}

void write_orderinfo(OINFO *oinfo)
{
	FILE *fp;
	OINFO *o = oinfo->next;
	char orderinfo[1000], *str_link = "|", *str_enter = "\n";
	if (fopen_s(&fp, "orderinfo.txt", "w"))
	{
		printf("file cannot be opened\n");
		//exit(1);
	}
	else
	{
		while (o)
		{
			strcpy_s(orderinfo, sizeof(orderinfo), o->order_id);
			strcat_s(orderinfo, sizeof(orderinfo), str_link);
			strcat_s(orderinfo, sizeof(orderinfo), o->state);
			strcat_s(orderinfo, sizeof(orderinfo), str_link);
			strcat_s(orderinfo, sizeof(orderinfo), o->passenger_id);
			strcat_s(orderinfo, sizeof(orderinfo), str_link);
			strcat_s(orderinfo, sizeof(orderinfo), o->passenger_name);
			strcat_s(orderinfo, sizeof(orderinfo), str_link);
			strcat_s(orderinfo, sizeof(orderinfo), o->train_num);
			strcat_s(orderinfo, sizeof(orderinfo), str_link);
			strcat_s(orderinfo, sizeof(orderinfo), o->station_s);
			strcat_s(orderinfo, sizeof(orderinfo), str_link);
			strcat_s(orderinfo, sizeof(orderinfo), o->station_d);
			strcat_s(orderinfo, sizeof(orderinfo), str_link);
			strcat_s(orderinfo, sizeof(orderinfo), o->ticket_type);
			strcat_s(orderinfo, sizeof(orderinfo), str_link);
			strcat_s(orderinfo, sizeof(orderinfo), o->ticket_price);
			strcat_s(orderinfo, sizeof(orderinfo), str_link);
			strcat_s(orderinfo, sizeof(orderinfo), str_enter);
			fprintf(fp, "%s", orderinfo);
			o = o->next;
		}

	}
	fclose(fp);
}

void read_orderinfo(OINFO *&oinfo)
{
	FILE *fp;
	OINFO *o = oinfo, *otemp;
	int i = 0, m = 0, n = 0, len;
	char str, str0, buf[MAX_LINE], tnum[10];
	if (fopen_s(&fp, "orderinfo.txt", "r"))
	{
		printf("file cannot be opened\n");
		exit(1);
	}
	else
	{
		while (fgets(buf, MAX_LINE, fp) != NULL)
		{
			i = 0;
			len = strlen(buf);
			buf[len - 1] = '\0';  /*ȥ�����з�*/
			//printf("%s %d \n", buf, len - 1);
			n = 0;
			otemp = (OINFO *)malloc(sizeof(OINFO));
			//6 | 1 | 450325199706170684 | ��Դ | G1 | ���� | ���� | 1 | 120 |
			while (1)
			{
				if (buf[i] == '|')
				{
					otemp->order_id[n] = '\0';
					i++;
					break;
				}
				otemp->order_id[n] = buf[i];
				n++;
				i++;
			}
			n = 0;
			while (1)
			{
				if (buf[i] == '|')
				{
					otemp->state[n] = '\0';
					i++;
					break;
				}
				otemp->state[n] = buf[i];
				n++;
				i++;
			}
			n = 0;
			while (1)
			{
				if (buf[i] == '|')
				{
					otemp->passenger_id[n] = '\0';
					i++;
					break;
				}
				otemp->passenger_id[n] = buf[i];
				n++;
				i++;
			}
			n = 0;
			while (1)
			{
				if (buf[i] == '|')
				{
					otemp->passenger_name[n] = '\0';
					i++;
					break;
				}
				otemp->passenger_name[n] = buf[i];
				n++;
				i++;
			}
			n = 0;
			while (1)
			{
				if (buf[i] == '|')
				{
					otemp->train_num[n] = '\0';
					i++;
					break;
				}
				otemp->train_num[n] = buf[i];
				n++;
				i++;
			}
			n = 0;
			while (1)
			{
				if (buf[i] == '|')
				{
					otemp->station_s[n] = '\0';
					i++;
					break;
				}
				otemp->station_s[n] = buf[i];
				n++;
				i++;
			}
			n = 0;
			while (1)
			{
				if (buf[i] == '|')
				{
					otemp->station_d[n] = '\0';
					i++;
					break;
				}
				otemp->station_d[n] = buf[i];
				n++;
				i++;
			}
			n = 0;
			while (1)
			{
				if (buf[i] == '|')
				{
					otemp->ticket_type[n] = '\0';
					i++;
					break;
				}
				otemp->ticket_type[n] = buf[i];
				n++;
				i++;
			}
			n = 0;
			while (1)
			{
				if (buf[i] == '|')
				{
					otemp->ticket_price[n] = '\0';
					i++;
					break;
				}
				otemp->ticket_price[n] = buf[i];
				n++;
				i++;
			}
			otemp->next = o->next;
			o->next = otemp;
			o = o->next;
		}
		o = NULL;

	}
	fclose(fp);

}

void read_all_orderinfo(OINFO *oinfo)
{
	FILE *fp;
	char buf[MAX_LINE];
	int i, len;
	if (fopen_s(&fp, "orderinfo.txt", "r"))
	{
		printf("file cannot be opened\n");
		exit(1);
	}
	while (fgets(buf, MAX_LINE, fp) != NULL)
	{
		i = 0;
		len = strlen(buf);
		buf[len - 1] = '\0';  /*ȥ�����з�*/
		printf("%s %d \n", buf, len - 1);
	}
	fclose(fp);
}

void search_order(OINFO *oinfo)
{
	OINFO *o;
	char oid[10], pid[30], pname[20];
	OQUEUE Q;
	int f = 0, m;
	printf("1--ͨ��������Ž��в�ѯ\n2--ͨ���û�id���û������в�ѯ\n");
	while (1)
	{
		printf("��ѡ���ѯ�����ķ�ʽ��");
		scanf_s("%d", &m);
		switch (m)
		{
		case 1:
		{
				  //ͨ��������Ž��в�ѯ
				  printf("������Ҫ���в�ѯ�Ķ�����ţ�");
				  _flushall();
				  gets_s(oid, sizeof(oid));
				  o = Locate_order_id(oinfo, oid);
				  if (o->next)
				  {
					  o = o->next;
					  printf("��ѯ���Ľ��Ϊ��\n");
					  printf("%s-%s-%s-%s-%s-%s-%s-%s\n", o->order_id, o->state, o->passenger_id, o->passenger_name, o->station_s, o->station_d, o->ticket_type, o->ticket_price);
				  }
				  else
					  printf("û�в�ѯ�������\n");
				  break;
		}
		case 2:
		{

				  //ͨ���û������û�id�鿴�û��Ķ�����Ϣ
				  f = 0;
				  printf("�������û�id��");
				  _flushall();
				  gets_s(pid, sizeof(pid));
				  printf("�������û�����");
				  _flushall();
				  gets_s(pname, sizeof(pname));
				  Q = Locate_pid_pname(oinfo, pid, pname);
				  printf("��ѯ���Ľ��Ϊ��\n");
				  while (!OQueueEmpty(Q))
				  {
					  f = 1;
					  ODeQueue(Q, o);
					  printf("�������-����״̬-�û�id-�û���-��ʼվ-�յ�վ-��Ʊ����-��Ʊ�۸�\n%s-%s-%s-%s-%s-%s-%s-%s\n", o->order_id, o->state, o->passenger_id, o->passenger_name, o->station_s, o->station_d, o->ticket_type, o->ticket_price);
				  }
				  if (!f)
					  printf("δ��ѯ�������\n");
				  break;
		}
		default:
		{
				   printf("\n");
				   break;
		}

		}
		printf("������ѯ�����롮/�����˳���ѯ�����롮#��");
		if (getchar() == '#')
			break;
	}
}

void del_orderinfo(OINFO *&oinfo)
{
	char del[5], *s0 = "0";
	OINFO *o, *temp;
	int i;
	//���ݶ�����Ų���
	printf("�Ƿ��ȶ���Ҫɾ���Ķ������в�ѯ���������롮1�������������롮0��\n");
	scanf_s("%d", &i);
	if (i)
		search_order(oinfo);
	printf("��������Ҫɾ���Ķ�����¼��ţ�");
	_flushall();
	gets_s(del, sizeof(del));
	o = Locate_order_id(oinfo, del);
	//���붩����ţ����˶�����¼ɾ��
	if (o->next&&strcmp(o->next->state, s0) == 0)
	{
		OListDelete(o, temp);
		write_orderinfo(oinfo);
		printf("������Ϊ%s�Ķ�����¼ɾ���ɹ���\n", o->next->order_id);
	}
	else
	{
		printf("�����ڴ��˵��ţ��������룡\n");
	}
}

void del_order_auto(OINFO *oinfo)
{
	OINFO *o = oinfo, *temp;
	char *s0 = "0";
	while (o->next)
	{
		if (strcmp(o->next->state, s0) == 0)
		{
			OListDelete(o, temp);
		}
		o = o->next;
	}
	write_orderinfo(oinfo);
	printf("�Զ�ɾ�����\n");
}

void cancel_ticket(TINFO *tinfo, OINFO *&oinfo)
{
	char oid[5], *s1 = "1", *s0 = "0";
	OINFO *o;
	QUEUE Q;
	TNODE *t;
	SEAT *s;
	int temp;
	InitQueue(Q);
	//ȷ�϶�Ʊ��Ϣ�Ƿ���ڣ�Ʊ�Ƿ��Ѿ�����
	search_order(oinfo);
	while (1)
	{
		printf("������Ҫ��Ʊ�Ķ�����ţ�");
		_flushall();
		gets_s(oid, sizeof(oid));
		o = Locate_order_id(oinfo, oid);
		if (o->next)
		{
			o = o->next;
			if (strcmp(o->state, s0) == 0)
			{
				printf("��ע���Ʊ�Ѿ����˶���\n");
			}
			if (strcmp(o->state, s1) == 0)
			{
				//ȷ�ϴ��ڶ�Ʊ��Ϣ��Ʊδ���ˣ�����Ʊ��Ϣ�ĵ���state��1��Ϊ0��traninfo�����о���վ����Ʊ��һ
				strcpy_s(o->state, sizeof(o->state), s0);
				Locate_train_route(tinfo->next, Q, o->station_s, o->station_d);
				while (!QueueEmpty(Q))
				{
					DeQueue(Q, t);
					s = t->seat->next;
					while (s)
					{
						if (strcmp(s->seat_type, o->ticket_type) == 0)
						{
							temp = atoi(s->ticket_left);
							temp++;
							_itoa_s(temp, s->ticket_left, 10);
							break;
						}
						s = s->next;
					}
				}
				write_traininfo(tinfo);
				write_orderinfo(oinfo);
				printf("��Ʊ�ɹ���\n");
				printf("��Ʊ��ϢΪ(�������-�û�id-�û���-��ʼվ-�յ�վ-��Ʊ����-��Ʊ�۸�)��\n%s-%s-%s-%s-%s-%s-%s\n", o->order_id, o->passenger_id, o->passenger_name, o->station_s, o->station_d, o->ticket_type, o->ticket_price);
			}
		}
		else
			printf("��ע��˶��������ڣ�\n");
		printf("�˳�ɾ��������¼�����롮#���������������������");
		if (getchar() == '#')
			break;

	}


}

void main()
{
	int m = 0, n = 0, p = 0;
	TINFO *tinfo;
	OINFO *oinfo;
	Init_tinfo(tinfo);
	Init_order(oinfo);
	read_traininfo(tinfo);
	read_orderinfo(oinfo);
	while (1)
	{
		printf("��ѡ������ϵͳ��\n1--����Աϵͳ\n2--�˿�ϵͳ\n");
		scanf_s("%d", &m);
		switch (m)
		{
		case 1:
		{
				  while (1)
				  {
					  printf("��ѡ�������\n1--�����г���Ϣ\n2--��������Ϣ\n");
					  scanf_s("%d", &n);
					  switch (n)
					  {

					  case 1:
					  {
								while (1)
								{
									printf("��ѡ��\n1--����г���Ϣ\n2--��������г���Ϣ\n3--ɾ���г���Ϣ\n4--�鿴�����г���Ϣ\n");
									scanf_s("%d", &p);
									switch (p)
									{
									case 1:
									{
											  input_train_info();
											  DestroyList(tinfo);
											  read_traininfo(tinfo);
											  break;
									}
									case 2:
									{
											  input_traininfo_fast();
											  DestroyList(tinfo);
											  read_traininfo(tinfo);
											  break;
									}
									case 3:
									{
											  del_traininfo(tinfo);
											  break;
									}
									case 4:
									{
											  read_all_traininfo(tinfo);
											  break;
									}
									default:
										break;
									}
									printf("�˳������г���Ϣ���롮#���������������������");
									_flushall();
									if (getchar() == '#')
										break;

								}
								break;

					  }
					  case 2:
					  {
								while (1)
								{
									printf("��ѡ��\n1--ѡ��ɾ�����˶����ļ�¼\n2--�����Զ�ɾ���������˶�����¼\n3--�鿴���ж�����Ϣ\n");
									scanf_s("%d", &p);
									switch (p)
									{
									case 1:
									{
											  del_orderinfo(oinfo);
											  break;
									}
									case 2:
									{
											  del_order_auto(oinfo);
											  break;
									}
									case 3:
									{
											  read_all_orderinfo(oinfo);
											  break;
									}
									default:
										break;
									}
									printf("�˳���������Ϣ���롮#���������������������");
									_flushall();
									if (getchar() == '#')
										break;


								}
					  }
					  }
					  printf("�˳�����Ա�������롮#�������κ���������������Ա������");
					  _flushall();
					  if (getchar() == '#')
						  break;
				  }
				  break;
		}
		case 2:
		{
				  while (1)
				  {
					  printf("��ѡ�������\n1--��Ʊ��ѯ\n2--��ƱԤ��\n3--��Ʊ\n4--��Ʊ��Ϣ��ѯ\n");
					  scanf_s("%d", &n);
					  switch (n)
					  {
					  case 1:
					  {
								search_traininfo(tinfo);
								break;
					  }
					  case 2:
					  {
								book_ticket(tinfo, oinfo);
								ODestroyList(oinfo);
								Init_order(oinfo);
								read_orderinfo(oinfo);
								break;
					  }
					  case 3:
					  {
								cancel_ticket(tinfo, oinfo);
								break;
					  }
					  case 4:
					  {
								ODestroyList(oinfo);
								Init_order(oinfo);
								read_orderinfo(oinfo);
								search_order(oinfo);
								break;
					  }
					  default:
						  break;
					  }
					  printf("�˳��˿Ͳ������롮#�������κ�����������\n");
					  _flushall();
					  if (getchar() == '#')
						  break;

				  }
				  break;

		}
		default:
			break;
		}
		printf("�˳���Ʊ����ϵͳ�����롮#�����������κμ���������\n");
		_flushall();
		if (getchar() == '#')
			break;

	}


}


