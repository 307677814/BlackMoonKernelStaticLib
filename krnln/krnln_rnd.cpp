#include "stdafx.h"

//�������� - ȡ�����
/*
    ���ø�ʽ�� �������͡� ȡ����� ���������� ��ȡ���������Сֵ�ݣ��������� ��ȡ����������ֵ�ݣ� - ϵͳ����֧�ֿ�->��������
    Ӣ�����ƣ�rnd
    ����һ��ָ����Χ�ڵ������ֵ����ʹ�ñ�����ȡһϵ�е������֮ǰ��Ӧ����ʹ�á�����������ӡ�����Ϊ�������������ʼ��һ������ֵ��������Ϊ�������
    ����<1>������Ϊ����ȡ���������Сֵ��������Ϊ�������ͣ�int���������Ա�ʡ�ԡ�����������ڻ�����㡣�����������ʡ�ԣ�Ĭ��Ϊ 0 ��
    ����<2>������Ϊ����ȡ����������ֵ��������Ϊ�������ͣ�int���������Ա�ʡ�ԡ�����������ڻ�����㡣�����������ʡ�ԣ�Ĭ��Ϊ���ޡ�
*/
LIBAPI(int, krnln_rnd)
{
/*
	INT nMin,nMax;
	PMDATA_INF pArg = &ArgInf;
	if(pArg[0].m_dtDataType == _SDT_NULL || pArg[0].m_int < 0)
		nMin = 0;
	else
		nMin = pArg[0].m_int;

	if(pArg[1].m_dtDataType == _SDT_NULL || pArg[1].m_int < 0)
		nMax = 0x7FFFFFFF;
	else
		nMax = pArg[1].m_int;
	INT nSub = nMax-nMin;
	if(nSub > 0 && nSub < RAND_MAX)
	{
		nSub++;
		nSub = (int)((double)rand()/((double)RAND_MAX/(double)nSub));

	}else if (nSub > RAND_MAX)
	{
		nSub = (int)((double)nSub*((double)rand()/(double)RAND_MAX));

	}else if(nSub == RAND_MAX)
	{
		nSub = rand();
	}

	return nSub+nMin;
*/
	PMDATA_INF pArg = &ArgInf;
  int v3; // esi@2
  int result; // eax@5
  int v5; // ecx@7
  signed int v6; // edi@13

  if (pArg[0].m_dtDataType != _SDT_NULL)
    v3 = pArg[0].m_int & ((pArg[0].m_int < 0) - 1);
  else
    v3 = 0;
  if (pArg[1].m_dtDataType != _SDT_NULL)
    result = ((pArg[1].m_int < 0) - 1) & pArg[1].m_int;
  else
    result = 2147483647;
  v5 = v3;
  if ( v3 >= result )
    v3 = result;
  if ( v5 > result )
    result = v5;
  if ( v3 == result )
  {
    result = v3;
  }
  else
  {
    result -= v3;
    v6 = 2147483646;
    if ( result <= 2147483646 )
      v6 = result;
    result = v3 + abs(rand()) % (v6 + 1);
  }
  return result;

}
