/*gru.h header file made by ValK*/
/*2019/5/7           version 1.1*/
#ifndef __GRU_H__
#define __GRU_H__
#include"rnn.h"

struct gru_neuron
{
	double *out;
	double *sig_update_in, *sig_update_out, *sig_update_wi, *sig_update_wh ;
	double *sig_replace_in,*sig_replace_out,*sig_replace_wi,*sig_replace_wh;
	double *tan_replace_in,*tan_replace_out,*tan_replace_wi,*tan_replace_wh;
	double sig_update_bia, sig_update_transbia ;
	double sig_replace_bia,sig_replace_transbia;
	double tan_replace_bia,tan_replace_transbia;
	double *sig_update_diff, *sig_update_transwi, *sig_update_transwh ;
	double *sig_replace_diff,*sig_replace_transwi,*sig_replace_transwh;
	double *tan_replace_diff,*tan_replace_transwi,*tan_replace_transwh;
};

class NormalGRU:public RNN
{
	public:
		gru_neuron *hide;
		NormalGRU(int,int,int);
		~NormalGRU();
		void INIT();
		void Datain(const char*);
		void Dataout(const char*);
};

class DeepGRU:public RNN
{
	public:
		gru_neuron *hlink;
		gru_neuron **hide;
		DeepGRU(int,int,int,int);
		~DeepGRU();
		void ConstructorAssist();
		void DestructorAssist();
		void INIT();
		void Datain(const char*);
		void Dataout(const char*);
};
#include "grufunction.h"

#endif
