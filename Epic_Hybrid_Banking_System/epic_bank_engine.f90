
! * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
! Epic Banking System 2.0 - Fortran Mathematical Engine
! Author: Leslie Brockman  
! Date: 2025-11-19
! Description: High-performance Fortran backend for Epic Banking ! System
! * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

module epic_bank_engine
    use, intrinsic :: iso_c_binding
    implicit none
    private
    
    public :: apply_interest_single
    public :: apply_service_charge_single
    public :: monte_carlo_risk_f

contains

    subroutine apply_interest_single(balance, rate) bind(c, name="apply_interest_f")
        real(c_double), intent(inout) :: balance
        real(c_double), intent(in)    :: rate
        
        balance = balance * (1.0_c_double + rate)
    end subroutine

    subroutine apply_service_charge_single(balance, charge) bind(c, name="apply_service_charge_f")
        real(c_double), intent(inout) :: balance
        real(c_double), intent(in)    :: charge
        
        balance = balance - charge
    end subroutine

    ! updated with geometric Brownian - real world loss/gains
    subroutine monte_carlo_risk_f(n_sims, balance, rate, volatility, years, risk_result) &
    bind(c, name="monte_carlo_risk_f")
    integer(c_int), intent(in)  :: n_sims, years
    real(c_double), intent(in)  :: balance, rate, volatility
    real(c_double), intent(out) :: risk_result
    real(c_double) :: u1, u2

    real(c_double) :: sim_balance, annual_return, z
    integer(c_int) :: i, y, ruined
    real(c_double), parameter :: sqrt_year = 1.0_c_double  ! 1 year steps

    call random_seed()
    ruined = 0

    do y = 1, years !
    ! Proper Box-Muller using two independent uniform draws
    call random_number(u1)
    call random_number(u2)
    if (u1 <= 0.0_c_double) u1 = 1.0e-12_c_double
    z = sqrt(-2.0_c_double * log(u1)) * cos(2.0_c_double * 3.141592653589793_c_double * u2)

    ! Exact GBM step (annual)
    annual_return = (rate - 0.5_c_double * volatility**2) + volatility * z
    sim_balance = sim_balance * exp(annual_return)

    if (sim_balance <= 0.0_c_double) then
        ruined = ruined + 1
        exit
    end if
end do

    risk_result = 100.0_c_double * real(ruined, c_double) / real(n_sims, c_double)
end subroutine

end module epic_bank_engine



   
! LEARNING NOTES - FORTRAN TO C++ INTEROP REFERENCE
! = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
!
! MODULE CONCEPTS:
! - module = creates a namespace (like C++ namespace)
! - organizes related functions together
! - use, intrinsic :: iso_c_binding = import C binding capabilities
! - implicit none = declare all variables, prevents typos from creating mystery vars
! - private = everything private by default, only public items visible to C++
! - public :: function_name = makes specific functions callable from C++
! - contains = required keyword that separates declarations from implementations
!
! SUBROUTINE CONCEPTS:
! - subroutine = Fortran function that doesn't return a value (like void in C++)
! - bind(c, name="apply_interest_f") = THE MAGIC for C++ interop!
!   - bind(c) = use C calling convention (no Fortran name mangling)
!   - name="exact_name" = C++ will call it by this EXACT name
! - real(c_double) = exactly matches C++ double type
! - intent(inout) = parameter can be modified (like C++ reference &)
! - intent(in) = parameter is read-only (like C++ const)
! - 1.0_c_double = ensures C-compatible double precision (not Fortran default)
!
! C++ SIDE REQUIREMENTS:
! - extern "C" { void apply_interest_f(double* balance, double* rate); }
! - Call with: apply_interest_f(&balance, &rate);
! - Fortran receives exact memory addresses, modifies directly
! - No copying, no conversion errors, pure speed!
!
! COMPILE PROCESS:
! 1. gfortran -shared -fPIC -o libepicbank.dylib epic_bank_engine.f90
! 2. g++ -o epicbank ch10exercise21_take7.cpp -L. -lepicbank -lgfortran
! 3. ./epicbank
!"Current banking systems: slow, unreliable floating-point math"
!"Hybrid C++/Fortran Architecture - Best of both worlds"
!"iso_c_binding - NASA-grade precision meets modern UI"

! MONTE CARLO SIMULATION CONCEPTS:
! - Runs thousands of "what if" scenarios with random market conditions
! - Each simulation: start with account balance, apply random returns for X years
! - Count how many simulations result in losing money (balance <= 0)
! - Risk percentage = (failures / total_simulations) * 100
! - Fortran handles the heavy math, C++ shows the pretty results
!Runs 10,000 market simulations
!Each simulation applies random market returns for N years
!Counts failures (balance goes to zero)
!Returns risk percentage

!geometric Brownian motion ??? --gold standard--cuss words
!Real Monte Carlo risk in savings/retirement accounts asks:
!Black-Scholes geometric Brownian motion — the same math hedge funds use.
!rare but possible huge gains
     !most years around +7–10%
        !crashes hurt more than booms help
!The log of balance tomorrow = log(balance today) + a tiny random walk
!Balance never goes negative
!Returns are multiplicative (which is how money !actually grows)
!Volatility scales correctly with time
!Uses the Box-Muller transform to generate normal random !variables.
!Applies the geometric Brownian motion formula for each year.
!Counts how many simulations end with a ruined (zero or !negative) balance.
!Returns the percentage of “ruined” outcomes as risk.
!friggin realstic finacial modeling--cuss words.
!Arithmetic returns simply add/subtract a percentage each year   
!Not realistic for compounding or risk modeling.
!Geometric Brownian motion (GBM) models returns as a random walk !in log-space:
!Returns are multiplicative (money compounds).
!Volatility and randomness are modeled using a normal !distribution.
!Used in Black-Scholes, hedge funds, and real finance.
!Returns are multiplicative (money compounds).
!Volatility and randomness are modeled using a normal !distribution.
!Used in Black-Scholes, hedge funds, and real finance.

!Line by Line break down
!random_seed(): Initializes the random number generator.
!do i = 1, n_sims: Runs thousands of simulations.
!sim_balance = balance: Start each simulation with the initial !balance.
!do y = 1, years: Simulate each year.
!call random_number(z): Get a random number between 0 and 1.
!Box-Muller transform: Converts uniform random to normal (bell curve) random.
!annual_return = ...: GBM formula for realistic returns.
!sim_balance = sim_balance * exp(annual_return): Compounds the !balance.
!if (sim_balance <= 0.0_c_double): If the account goes broke, !count as "ruined".
!risk_result = ...: Calculates the percentage of ruined outcomes.

!"Ruined" means the account balance hit zero or negative in a !simulation.
!realistic risk metric: "What % chance do I go broke in X years?"

!Geometric vs Arithmetic 
!Arithmetic: "Add 7% every year, ignore randomness."
!Geometric: "Each year, returns are random, compounding, and can !crash or boom."
!GBM: "Used by Wall Street, models real risk, rare huge gains, !possible big losses."




