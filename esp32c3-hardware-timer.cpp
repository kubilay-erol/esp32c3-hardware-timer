
#include<cstdint>


constexpr uint64_t num = 3;

class Time {

public:
    uint64_t reference[num];

    uint64_t get_timer() {


        *(reinterpret_cast<volatile uint32_t*>(0x6001F00C)) = 1;   //write anything on latch  


        uint32_t low = *(reinterpret_cast<volatile uint32_t*>(0x6001F004)); //low 
       
        uint32_t high = *(reinterpret_cast<volatile uint32_t*>(0x6001F008)); //high
        

        uint64_t microseconds = (static_cast<uint64_t>(high) << 32) | low;

        return microseconds; 
    }

    uint64_t get_seconds(uint64_t micsec) {
        return micsec/1'000'000;
    }

    void set_ref(uint64_t n) {
        reference[n] = get_timer();
    }      

    uint64_t get_time(uint64_t n) {
        return get_seconds((get_timer() - reference[n]));
    }

    bool is_delay_complete(uint64_t delay_seconds, uint64_t n) {
     // Check if the elapsed time has reached or exceeded the target delay
        if (get_time(n) >= delay_seconds) {
            return true; 
        }
        return false;
}
};





   
