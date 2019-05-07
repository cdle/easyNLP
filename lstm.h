/*lstm.h header file made by ValK*/
/*2019/5/7            version 1.1*/
#ifndef __LSTM_H__
#define __LSTM_H__
#include"rnn.h"

struct lstm_neuron
{
	double *cell;
	double *out;
	double *fog_in,*fog_out,fog_bia,*fog_wi,*fog_wh,*fog_diff;
	double *sig_in,*sig_out,sig_bia,*sig_wi,*sig_wh,*sig_diff;
	double *tan_in,*tan_out,tan_bia,*tan_wi,*tan_wh,*tan_diff;
	double *out_in,*out_out,out_bia,*out_wi,*out_wh,*out_diff;
	double fog_transbia,*fog_transwi,*fog_transwh;
	double sig_transbia,*sig_transwi,*sig_transwh;
	double tan_transbia,*tan_transwi,*tan_transwh;
	double out_transbia,*out_transwi,*out_transwh;
};

class NormalLSTM:public RNN
{
	public:
		lstm_neuron *hide;
		NormalLSTM(int,int,int);
		~NormalLSTM();
		void INIT();
		void Datain(const char*);
		void Dataout(const char*);
};

class DeepLSTM:public RNN
{
	public:
		lstm_neuron *hlink;
		lstm_neuron **hide;
		DeepLSTM(int,int,int,int);
		~DeepLSTM();
		void ConstructorAssist();
		void DestructorAssist();
		void INIT();
		void Datain(const char*);
		void Dataout(const char*);
};

#include "lstmfunction.h"

#endif
