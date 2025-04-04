/* === S Y N F I G ========================================================= */
/*!	\file benchmark.cpp
**	\brief Benchmark test
**
**	\legal
** Copyright (c) 2002 Robert B. Quattlebaum Jr.
**
** This file is part of Synfig.
**
** Synfig is free software: you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation, either version 2 of the License, or
** (at your option) any later version.
**
** Synfig is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with Synfig.  If not, see <https://www.gnu.org/licenses/>.
**
** ========================================================================= */

/* === H E A D E R S ======================================================= */

#include <cstdio>

#include <synfig/angle.h>
#include <synfig/bezier.h>
#include <synfig/clock.h>
#include <synfig/surface_etl.h>

/* === M A C R O S ========================================================= */

using namespace synfig;

#define HERMITE_TEST_ITERATIONS		(100000)

/* === C L A S S E S ======================================================= */

/* === P R O C E D U R E S ================================================= */

template <class Angle>
void angle_cos_speed_test(void)
{
	Angle a,b,c,d;
	float tmp,tmp2;

	for(tmp=-1;tmp<1;tmp+=0.000002f)
	{
		a=(typename Angle::cos)(tmp);
		b=(typename Angle::cos)(tmp);
		c=(typename Angle::cos)(tmp);
		d=(typename Angle::cos)(tmp);
		tmp2=((typename Angle::cos)(a)).get();
		tmp2=((typename Angle::cos)(b)).get();
		tmp2=((typename Angle::cos)(c)).get();
		tmp2=((typename Angle::cos)(d)).get();
	}
	if (tmp2 == 0) return; // disable unused warning
}
template <class Angle>
void angle_sin_speed_test(void)
{
	Angle a,b,c,d;
	float tmp,tmp2;

	for(tmp=-1.0;tmp<1.0;tmp+=0.000002f)
	{
		a=(typename Angle::sin)(tmp);
		b=(typename Angle::sin)(tmp);
		c=(typename Angle::sin)(tmp);
		d=(typename Angle::sin)(tmp);
		tmp2=((typename Angle::sin)(a)).get();
		tmp2=((typename Angle::sin)(b)).get();
		tmp2=((typename Angle::sin)(c)).get();
		tmp2=((typename Angle::sin)(d)).get();
	}
	if (tmp2 == 0) return; // disable unused warning
}
template <class Angle>
void angle_tan_speed_test(void)
{
	Angle a,b,c,d;
	float tmp,tmp2;

	for(tmp=-1;tmp<1;tmp+=0.000002f)
	{
		a=(typename Angle::tan)(tmp);
		b=(typename Angle::tan)(tmp);
		c=(typename Angle::tan)(tmp);
		d=(typename Angle::tan)(tmp);
		tmp2=((typename Angle::tan)(a)).get();
		tmp2=((typename Angle::tan)(b)).get();
		tmp2=((typename Angle::tan)(c)).get();
		tmp2=((typename Angle::tan)(d)).get();
	}
	if (tmp2 == 0) return; // disable unused warning
}
template <class Angle, class mytan>
void angle_atan2_speed_test(void)
{
	Angle a,b,c;
	float x,y;

	for(y=-10;y<10;y+=0.05f)
		for(x=-10;x<10;x+=0.05f)
		{
			a=mytan(y,x);
			a=mytan(x,y);
			b=mytan(y,x);
			b=mytan(x,y);
			c=mytan(y,x);
			c=mytan(x,y);
			a=mytan(y,x);
			a=mytan(x,y);
			b=mytan(y,x);
			b=mytan(x,y);
			c=mytan(y,x);
			c=mytan(x,y);
		}
}


int hermite_int_test()
{
	int ret=0;
	hermite<int> Hermie;
	hermite<int>::time_type f;
	int i;

	synfig::clock timer;
	float t = 0.0;

	Hermie.p1()=0;
	Hermie.t1()=40000;
	Hermie.p2()=0;
	Hermie.t2()=40000;

	Hermie.sync();

	{
	for(f=0.0f,i=0,timer.reset();i<HERMITE_TEST_ITERATIONS;i++,f+=0.000005f)
	{
		t+=Hermie(f)+Hermie(f+0.1f);
		t+=Hermie(f)+Hermie(f+0.1f);
		t+=Hermie(f)+Hermie(f+0.1f);
		t+=Hermie(f)+Hermie(f+0.1f);
		t+=Hermie(f)+Hermie(f+0.1f);
		t+=Hermie(f)+Hermie(f+0.1f);
		t+=Hermie(f)+Hermie(f+0.1f);
		t+=Hermie(f)+Hermie(f+0.1f);
		t+=Hermie(f)+Hermie(f+0.1f);
		t+=Hermie(f)+Hermie(f+0.1f);
		t+=Hermie(f)+Hermie(f+0.1f);
		t+=Hermie(f)+Hermie(f+0.1f);
	}
	}
	t=timer();

	printf("hermite<int>:time=%f milliseconds\n",t*1000);
	return ret;
}

int hermite_float_test(void)
{
	int ret=0;
	float f; int i;

	hermite<float> Hermie;
	synfig::clock timer;
	double t;

	Hermie.p1()=0;
	Hermie.t1()=1;
	Hermie.p2()=0;
	Hermie.t2()=1;

	Hermie.sync();

	{
	for(f=0.0f,i=0,timer.reset();i<HERMITE_TEST_ITERATIONS;i++,f+=0.000005f)
	{
		t+=Hermie(f)+Hermie(f+0.1f);
		t+=Hermie(f)+Hermie(f+0.1f);
		t+=Hermie(f)+Hermie(f+0.1f);
		t+=Hermie(f)+Hermie(f+0.1f);
		t+=Hermie(f)+Hermie(f+0.1f);
		t+=Hermie(f)+Hermie(f+0.1f);
		t+=Hermie(f)+Hermie(f+0.1f);
		t+=Hermie(f)+Hermie(f+0.1f);
		t+=Hermie(f)+Hermie(f+0.1f);
		t+=Hermie(f)+Hermie(f+0.1f);
		t+=Hermie(f)+Hermie(f+0.1f);
		t+=Hermie(f)+Hermie(f+0.1f);
	}
	}
	t=timer();

	printf("hermite<float>:time=%f milliseconds\n",t*1000);
	return ret;
}

int hermite_double_test(void)
{
	int ret=0,i;
	float f;

	hermite<double> Hermie;
	synfig::clock timer;
	double t = 0.0;

	Hermie.p1()=0;
	Hermie.t1()=1;
	Hermie.p2()=0;
	Hermie.t2()=1;

	Hermie.sync();

	for(f=0.0f,i=0,timer.reset();i<HERMITE_TEST_ITERATIONS;i++,f+=0.000005f)
	{
		t+=Hermie(f)+Hermie(f+0.1f);
		t+=Hermie(f)+Hermie(f+0.1f);
		t+=Hermie(f)+Hermie(f+0.1f);
		t+=Hermie(f)+Hermie(f+0.1f);
		t+=Hermie(f)+Hermie(f+0.1f);
		t+=Hermie(f)+Hermie(f+0.1f);
		t+=Hermie(f)+Hermie(f+0.1f);
		t+=Hermie(f)+Hermie(f+0.1f);
		t+=Hermie(f)+Hermie(f+0.1f);
		t+=Hermie(f)+Hermie(f+0.1f);
		t+=Hermie(f)+Hermie(f+0.1f);
		t+=Hermie(f)+Hermie(f+0.1f);
	}
	t=timer();

	printf("hermite<double>:time=%f milliseconds\n",t*1000);
	return ret;
}

int hermite_angle_test(void)
{
	using namespace synfig;

	int ret=0,i;
	float f;

	hermite<Angle> Hermie;
	synfig::clock timer;
	Angle tmp;
	double t;

	Hermie.p1()=Angle::deg(0);
	Hermie.t1()=Angle::deg(45);

	Hermie.p2()=Angle::deg(-45);
	Hermie.t2()=Angle::deg(180);

	Hermie.sync();

	for(f=0.0f,i=0,timer.reset();i<HERMITE_TEST_ITERATIONS;i++,f+=0.000005f)
	{
		tmp+=Hermie(f)+Hermie(f+0.1f);
		tmp+=Hermie(f)+Hermie(f+0.1f);
		tmp+=Hermie(f)+Hermie(f+0.1f);
		tmp+=Hermie(f)+Hermie(f+0.1f);
		tmp+=Hermie(f)+Hermie(f+0.1f);
		tmp+=Hermie(f)+Hermie(f+0.1f);
		tmp+=Hermie(f)+Hermie(f+0.1f);
		tmp+=Hermie(f)+Hermie(f+0.1f);
		tmp+=Hermie(f)+Hermie(f+0.1f);
		tmp+=Hermie(f)+Hermie(f+0.1f);
		tmp+=Hermie(f)+Hermie(f+0.1f);
		tmp+=Hermie(f)+Hermie(f+0.1f);
	}
	t=timer();

	fprintf(stderr,"hermite<angle>:time=%f milliseconds\n",t*1000);

	return ret;
}


/* === E N T R Y P O I N T ================================================= */

int main()
{
	int error=0;

	error+=hermite_float_test();
	error+=hermite_double_test();
	error+=hermite_int_test();
	error+=hermite_angle_test();

	return error;
}
