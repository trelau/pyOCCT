/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC
Copyright (C) 2019 Trevor Laughlin and the pyOCCT contributors

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/
#include <pyOCCT_Common.hxx>

void bind_Quantity_NameOfColor(py::module &);
void bind_Quantity_TypeOfColor(py::module &);
void bind_Quantity_PhysicalQuantity(py::module &);
void bind_Quantity_Color(py::module &);
void bind_Quantity_ColorRGBA(py::module &);
void bind_Quantity_Array1OfColor(py::module &);
void bind_Quantity_HArray1OfColor(py::module &);
void bind_Quantity_ColorHasher(py::module &);
void bind_Quantity_ColorRGBAHasher(py::module &);
void bind_Quantity_AbsorbedDose(py::module &);
void bind_Quantity_Acceleration(py::module &);
void bind_Quantity_AcousticIntensity(py::module &);
void bind_Quantity_Activity(py::module &);
void bind_Quantity_Admittance(py::module &);
void bind_Quantity_AmountOfSubstance(py::module &);
void bind_Quantity_AngularVelocity(py::module &);
void bind_Quantity_Area(py::module &);
void bind_Quantity_Array2OfColor(py::module &);
void bind_Quantity_Capacitance(py::module &);
void bind_Quantity_Coefficient(py::module &);
void bind_Quantity_CoefficientOfExpansion(py::module &);
void bind_Quantity_ColorDefinitionError(py::module &);
void bind_Quantity_Concentration(py::module &);
void bind_Quantity_Conductivity(py::module &);
void bind_Quantity_Constant(py::module &);
void bind_Quantity_Consumption(py::module &);
void bind_Quantity_Content(py::module &);
void bind_Quantity_Date(py::module &);
void bind_Quantity_DateDefinitionError(py::module &);
void bind_Quantity_Density(py::module &);
void bind_Quantity_DoseEquivalent(py::module &);
void bind_Quantity_ElectricCapacitance(py::module &);
void bind_Quantity_ElectricCharge(py::module &);
void bind_Quantity_ElectricCurrent(py::module &);
void bind_Quantity_ElectricFieldStrength(py::module &);
void bind_Quantity_ElectricPotential(py::module &);
void bind_Quantity_Energy(py::module &);
void bind_Quantity_Enthalpy(py::module &);
void bind_Quantity_Entropy(py::module &);
void bind_Quantity_Factor(py::module &);
void bind_Quantity_Force(py::module &);
void bind_Quantity_Frequency(py::module &);
void bind_Quantity_Illuminance(py::module &);
void bind_Quantity_Impedance(py::module &);
void bind_Quantity_Index(py::module &);
void bind_Quantity_Inductance(py::module &);
void bind_Quantity_KinematicViscosity(py::module &);
void bind_Quantity_KineticMoment(py::module &);
void bind_Quantity_Length(py::module &);
void bind_Quantity_Luminance(py::module &);
void bind_Quantity_LuminousEfficacity(py::module &);
void bind_Quantity_LuminousExposition(py::module &);
void bind_Quantity_LuminousFlux(py::module &);
void bind_Quantity_LuminousIntensity(py::module &);
void bind_Quantity_MagneticFieldStrength(py::module &);
void bind_Quantity_MagneticFlux(py::module &);
void bind_Quantity_MagneticFluxDensity(py::module &);
void bind_Quantity_Mass(py::module &);
void bind_Quantity_MassFlow(py::module &);
void bind_Quantity_MolarConcentration(py::module &);
void bind_Quantity_Molarity(py::module &);
void bind_Quantity_MolarMass(py::module &);
void bind_Quantity_MolarVolume(py::module &);
void bind_Quantity_MomentOfAForce(py::module &);
void bind_Quantity_MomentOfInertia(py::module &);
void bind_Quantity_Momentum(py::module &);
void bind_Quantity_Normality(py::module &);
void bind_Quantity_Parameter(py::module &);
void bind_Quantity_Period(py::module &);
void bind_Quantity_PeriodDefinitionError(py::module &);
void bind_Quantity_PlaneAngle(py::module &);
void bind_Quantity_Power(py::module &);
void bind_Quantity_Pressure(py::module &);
void bind_Quantity_Quotient(py::module &);
void bind_Quantity_Rate(py::module &);
void bind_Quantity_Ratio(py::module &);
void bind_Quantity_Reluctance(py::module &);
void bind_Quantity_Resistance(py::module &);
void bind_Quantity_Resistivity(py::module &);
void bind_Quantity_Scalaire(py::module &);
void bind_Quantity_SolidAngle(py::module &);
void bind_Quantity_SoundIntensity(py::module &);
void bind_Quantity_SpecificHeatCapacity(py::module &);
void bind_Quantity_Speed(py::module &);
void bind_Quantity_SurfaceTension(py::module &);
void bind_Quantity_Temperature(py::module &);
void bind_Quantity_ThermalConductivity(py::module &);
void bind_Quantity_Torque(py::module &);
void bind_Quantity_Velocity(py::module &);
void bind_Quantity_Viscosity(py::module &);
void bind_Quantity_Volume(py::module &);
void bind_Quantity_VolumeFlow(py::module &);
void bind_Quantity_Weight(py::module &);
void bind_Quantity_Work(py::module &);

PYBIND11_MODULE(Quantity, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.NCollection");

bind_Quantity_NameOfColor(mod);
bind_Quantity_TypeOfColor(mod);
bind_Quantity_PhysicalQuantity(mod);
bind_Quantity_Color(mod);
bind_Quantity_ColorRGBA(mod);
bind_Quantity_Array1OfColor(mod);
bind_Quantity_HArray1OfColor(mod);
bind_Quantity_ColorHasher(mod);
bind_Quantity_ColorRGBAHasher(mod);
bind_Quantity_AbsorbedDose(mod);
bind_Quantity_Acceleration(mod);
bind_Quantity_AcousticIntensity(mod);
bind_Quantity_Activity(mod);
bind_Quantity_Admittance(mod);
bind_Quantity_AmountOfSubstance(mod);
bind_Quantity_AngularVelocity(mod);
bind_Quantity_Area(mod);
bind_Quantity_Array2OfColor(mod);
bind_Quantity_Capacitance(mod);
bind_Quantity_Coefficient(mod);
bind_Quantity_CoefficientOfExpansion(mod);
bind_Quantity_ColorDefinitionError(mod);
bind_Quantity_Concentration(mod);
bind_Quantity_Conductivity(mod);
bind_Quantity_Constant(mod);
bind_Quantity_Consumption(mod);
bind_Quantity_Content(mod);
bind_Quantity_Date(mod);
bind_Quantity_DateDefinitionError(mod);
bind_Quantity_Density(mod);
bind_Quantity_DoseEquivalent(mod);
bind_Quantity_ElectricCapacitance(mod);
bind_Quantity_ElectricCharge(mod);
bind_Quantity_ElectricCurrent(mod);
bind_Quantity_ElectricFieldStrength(mod);
bind_Quantity_ElectricPotential(mod);
bind_Quantity_Energy(mod);
bind_Quantity_Enthalpy(mod);
bind_Quantity_Entropy(mod);
bind_Quantity_Factor(mod);
bind_Quantity_Force(mod);
bind_Quantity_Frequency(mod);
bind_Quantity_Illuminance(mod);
bind_Quantity_Impedance(mod);
bind_Quantity_Index(mod);
bind_Quantity_Inductance(mod);
bind_Quantity_KinematicViscosity(mod);
bind_Quantity_KineticMoment(mod);
bind_Quantity_Length(mod);
bind_Quantity_Luminance(mod);
bind_Quantity_LuminousEfficacity(mod);
bind_Quantity_LuminousExposition(mod);
bind_Quantity_LuminousFlux(mod);
bind_Quantity_LuminousIntensity(mod);
bind_Quantity_MagneticFieldStrength(mod);
bind_Quantity_MagneticFlux(mod);
bind_Quantity_MagneticFluxDensity(mod);
bind_Quantity_Mass(mod);
bind_Quantity_MassFlow(mod);
bind_Quantity_MolarConcentration(mod);
bind_Quantity_Molarity(mod);
bind_Quantity_MolarMass(mod);
bind_Quantity_MolarVolume(mod);
bind_Quantity_MomentOfAForce(mod);
bind_Quantity_MomentOfInertia(mod);
bind_Quantity_Momentum(mod);
bind_Quantity_Normality(mod);
bind_Quantity_Parameter(mod);
bind_Quantity_Period(mod);
bind_Quantity_PeriodDefinitionError(mod);
bind_Quantity_PlaneAngle(mod);
bind_Quantity_Power(mod);
bind_Quantity_Pressure(mod);
bind_Quantity_Quotient(mod);
bind_Quantity_Rate(mod);
bind_Quantity_Ratio(mod);
bind_Quantity_Reluctance(mod);
bind_Quantity_Resistance(mod);
bind_Quantity_Resistivity(mod);
bind_Quantity_Scalaire(mod);
bind_Quantity_SolidAngle(mod);
bind_Quantity_SoundIntensity(mod);
bind_Quantity_SpecificHeatCapacity(mod);
bind_Quantity_Speed(mod);
bind_Quantity_SurfaceTension(mod);
bind_Quantity_Temperature(mod);
bind_Quantity_ThermalConductivity(mod);
bind_Quantity_Torque(mod);
bind_Quantity_Velocity(mod);
bind_Quantity_Viscosity(mod);
bind_Quantity_Volume(mod);
bind_Quantity_VolumeFlow(mod);
bind_Quantity_Weight(mod);
bind_Quantity_Work(mod);

}
