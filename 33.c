#include<stdio.h>
#include<string.h>
#define TransportationText(TYPE) \
	char name[20];\
	double speed;\
	double distance;\
	int (*price)(struct TYPE*);\
	double (*time)(struct TYPE*)
typedef struct data_s{
	int price;
	double time;
	char name[20];
}data_t;
typedef struct car_s {
	int oilPrice;
	int parkPrice;
	int tolls;
	TransportationText(car_s);
} car_t;
typedef struct bike_s {
	int rentPrice;
	TransportationText(bike_s);
} bike_t;
typedef struct bus_s {
	int staticPrice;
	int extendPrice;
	TransportationText(bus_s);
} bus_t;
typedef struct scooter_s {
	int oilPrice;
	TransportationText(scooter_s);
} scooter_t;
int CarPrice(car_t* obj){
	double d = obj->distance;
	int t = d/100;
	t=((int)d%100==0)?t:t+1;
	t = (t==0)?1:t;
	return obj->parkPrice + (obj->oilPrice * 10 + obj->tolls) * t;
}
double CarTime(car_t* obj){
	return obj->distance/obj->speed;
}
int BikePrice(bike_t* obj){
	return obj->rentPrice;
}
double BikeTime(bike_t* obj){
	return obj->distance/obj->speed;	
}
int BusPrice(bus_t* obj){
	double d = obj->distance - 100;
	int t = d/50;
	t = ((int)d%50==0)?t:t+1;
	t = (t==0)?1:t;
	return obj->staticPrice + t * obj->extendPrice;
}
double BusTime(bus_t* obj){
	return obj->distance/obj->speed;
}
int ScooterPrice(scooter_t* obj){
	double d = obj->distance;
	int t = d/100;
	t = ((int)d%100==0)?t:t+1;
	t = (t==0)?1:t;
	return obj->oilPrice * t * 4;
}
double ScooterTime(scooter_t* obj){
	return obj->distance/obj->speed;
}
void CarCreate(car_t *obj,int x){
	strcpy(obj->name, "Car");
	obj->speed = 100;
	obj->price = CarPrice;
	obj->time = CarTime;
	obj->distance = x;
}
void BikeCreate(bike_t *obj,int x){
	strcpy(obj->name, "Bike");
	obj->speed = 20;
	obj->price = BikePrice;
	obj->time = BikeTime;
	obj->distance = x;
}
void BusCreate(bus_t *obj,int x){
	strcpy(obj->name, "Intercity Bus");
	obj->speed = 75;
	obj->price = BusPrice;
	obj->time = BusTime;
	obj->distance = x;
}
void ScooterCreate(scooter_t *obj,int x){
	strcpy(obj->name, "Scooter");
	obj->speed = 50;
	obj->price = ScooterPrice;
	obj->time = ScooterTime;
	obj->distance = x;
}
int main(){
	int x,y;
	scanf("%d%d",&x,&y);
	car_t a;
	bike_t b;
	bus_t c;
	scooter_t d;
	CarCreate(&a,x);
	BikeCreate(&b,x);
	BusCreate(&c,x);
	ScooterCreate(&d,x);
	scanf("%d%d%d%d%d%d%d",&a.oilPrice,&a.parkPrice,&a.tolls,&b.rentPrice,&c.staticPrice,&c.extendPrice,&d.oilPrice);
	data_t data[4];
	data_t *tmp=NULL;
	data[0].price=a.price(&a);
	data[0].time=a.time(&a);
	strcpy(data[0].name,a.name);
	data[1].price=b.price(&b);
	data[1].time=b.time(&b);
	strcpy(data[1].name,b.name);
	data[2].price=c.price(&c);
	data[2].time=c.time(&c);
	strcpy(data[2].name,c.name);
	data[3].price=d.price(&d);
	data[3].time=d.time(&d);
	strcpy(data[3].name,d.name);
	int mintime=9999999;
	char tp[20];
	int i;
	for(i=0;i<4;i++){
		if(data[i].price<=y && data[i].time<mintime){
			tmp = &data[i];
			mintime = data[i].time;
		}
	}
	if(tmp!=NULL){
		printf("%s\n%d\n%.2f",tmp->name,tmp->price,tmp->time);
	}
	else puts("No Transportation");
	return 0;
}