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
#include <Quantity_PhysicalQuantity.hxx>

void bind_Quantity_PhysicalQuantity(py::module &mod){

py::enum_<Quantity_PhysicalQuantity>(mod, "Quantity_PhysicalQuantity", "List of all physical quantities(Afnor)")
	.value("Quantity_MASS", Quantity_PhysicalQuantity::Quantity_MASS)
	.value("Quantity_PLANEANGLE", Quantity_PhysicalQuantity::Quantity_PLANEANGLE)
	.value("Quantity_SOLIDANGLE", Quantity_PhysicalQuantity::Quantity_SOLIDANGLE)
	.value("Quantity_LENGTH", Quantity_PhysicalQuantity::Quantity_LENGTH)
	.value("Quantity_AREA", Quantity_PhysicalQuantity::Quantity_AREA)
	.value("Quantity_VOLUME", Quantity_PhysicalQuantity::Quantity_VOLUME)
	.value("Quantity_SPEED", Quantity_PhysicalQuantity::Quantity_SPEED)
	.value("Quantity_VELOCITY", Quantity_PhysicalQuantity::Quantity_VELOCITY)
	.value("Quantity_ACCELERATION", Quantity_PhysicalQuantity::Quantity_ACCELERATION)
	.value("Quantity_ANGULARVELOCITY", Quantity_PhysicalQuantity::Quantity_ANGULARVELOCITY)
	.value("Quantity_FREQUENCY", Quantity_PhysicalQuantity::Quantity_FREQUENCY)
	.value("Quantity_TEMPERATURE", Quantity_PhysicalQuantity::Quantity_TEMPERATURE)
	.value("Quantity_AMOUNTOFSUBSTANCE", Quantity_PhysicalQuantity::Quantity_AMOUNTOFSUBSTANCE)
	.value("Quantity_DENSITY", Quantity_PhysicalQuantity::Quantity_DENSITY)
	.value("Quantity_MASSFLOW", Quantity_PhysicalQuantity::Quantity_MASSFLOW)
	.value("Quantity_VOLUMEFLOW", Quantity_PhysicalQuantity::Quantity_VOLUMEFLOW)
	.value("Quantity_CONSUMPTION", Quantity_PhysicalQuantity::Quantity_CONSUMPTION)
	.value("Quantity_MOMENTUM", Quantity_PhysicalQuantity::Quantity_MOMENTUM)
	.value("Quantity_KINETICMOMENT", Quantity_PhysicalQuantity::Quantity_KINETICMOMENT)
	.value("Quantity_MOMENTOFINERTIA", Quantity_PhysicalQuantity::Quantity_MOMENTOFINERTIA)
	.value("Quantity_FORCE", Quantity_PhysicalQuantity::Quantity_FORCE)
	.value("Quantity_MOMENTOFAFORCE", Quantity_PhysicalQuantity::Quantity_MOMENTOFAFORCE)
	.value("Quantity_TORQUE", Quantity_PhysicalQuantity::Quantity_TORQUE)
	.value("Quantity_WEIGHT", Quantity_PhysicalQuantity::Quantity_WEIGHT)
	.value("Quantity_PRESSURE", Quantity_PhysicalQuantity::Quantity_PRESSURE)
	.value("Quantity_VISCOSITY", Quantity_PhysicalQuantity::Quantity_VISCOSITY)
	.value("Quantity_KINEMATICVISCOSITY", Quantity_PhysicalQuantity::Quantity_KINEMATICVISCOSITY)
	.value("Quantity_ENERGY", Quantity_PhysicalQuantity::Quantity_ENERGY)
	.value("Quantity_WORK", Quantity_PhysicalQuantity::Quantity_WORK)
	.value("Quantity_POWER", Quantity_PhysicalQuantity::Quantity_POWER)
	.value("Quantity_SURFACETENSION", Quantity_PhysicalQuantity::Quantity_SURFACETENSION)
	.value("Quantity_COEFFICIENTOFEXPANSION", Quantity_PhysicalQuantity::Quantity_COEFFICIENTOFEXPANSION)
	.value("Quantity_THERMALCONDUCTIVITY", Quantity_PhysicalQuantity::Quantity_THERMALCONDUCTIVITY)
	.value("Quantity_SPECIFICHEATCAPACITY", Quantity_PhysicalQuantity::Quantity_SPECIFICHEATCAPACITY)
	.value("Quantity_ENTROPY", Quantity_PhysicalQuantity::Quantity_ENTROPY)
	.value("Quantity_ENTHALPY", Quantity_PhysicalQuantity::Quantity_ENTHALPY)
	.value("Quantity_LUMINOUSINTENSITY", Quantity_PhysicalQuantity::Quantity_LUMINOUSINTENSITY)
	.value("Quantity_LUMINOUSFLUX", Quantity_PhysicalQuantity::Quantity_LUMINOUSFLUX)
	.value("Quantity_LUMINANCE", Quantity_PhysicalQuantity::Quantity_LUMINANCE)
	.value("Quantity_ILLUMINANCE", Quantity_PhysicalQuantity::Quantity_ILLUMINANCE)
	.value("Quantity_LUMINOUSEXPOSITION", Quantity_PhysicalQuantity::Quantity_LUMINOUSEXPOSITION)
	.value("Quantity_LUMINOUSEFFICACITY", Quantity_PhysicalQuantity::Quantity_LUMINOUSEFFICACITY)
	.value("Quantity_ELECTRICCHARGE", Quantity_PhysicalQuantity::Quantity_ELECTRICCHARGE)
	.value("Quantity_ELECTRICCURRENT", Quantity_PhysicalQuantity::Quantity_ELECTRICCURRENT)
	.value("Quantity_ELECTRICFIELDSTRENGTH", Quantity_PhysicalQuantity::Quantity_ELECTRICFIELDSTRENGTH)
	.value("Quantity_ELECTRICPOTENTIAL", Quantity_PhysicalQuantity::Quantity_ELECTRICPOTENTIAL)
	.value("Quantity_ELECTRICCAPACITANCE", Quantity_PhysicalQuantity::Quantity_ELECTRICCAPACITANCE)
	.value("Quantity_MAGNETICFLUX", Quantity_PhysicalQuantity::Quantity_MAGNETICFLUX)
	.value("Quantity_MAGNETICFLUXDENSITY", Quantity_PhysicalQuantity::Quantity_MAGNETICFLUXDENSITY)
	.value("Quantity_MAGNETICFIELDSTRENGTH", Quantity_PhysicalQuantity::Quantity_MAGNETICFIELDSTRENGTH)
	.value("Quantity_RELUCTANCE", Quantity_PhysicalQuantity::Quantity_RELUCTANCE)
	.value("Quantity_RESISTANCE", Quantity_PhysicalQuantity::Quantity_RESISTANCE)
	.value("Quantity_INDUCTANCE", Quantity_PhysicalQuantity::Quantity_INDUCTANCE)
	.value("Quantity_CAPACITANCE", Quantity_PhysicalQuantity::Quantity_CAPACITANCE)
	.value("Quantity_IMPEDANCE", Quantity_PhysicalQuantity::Quantity_IMPEDANCE)
	.value("Quantity_ADMITTANCE", Quantity_PhysicalQuantity::Quantity_ADMITTANCE)
	.value("Quantity_RESISTIVITY", Quantity_PhysicalQuantity::Quantity_RESISTIVITY)
	.value("Quantity_CONDUCTIVITY", Quantity_PhysicalQuantity::Quantity_CONDUCTIVITY)
	.value("Quantity_MOLARMASS", Quantity_PhysicalQuantity::Quantity_MOLARMASS)
	.value("Quantity_MOLARVOLUME", Quantity_PhysicalQuantity::Quantity_MOLARVOLUME)
	.value("Quantity_CONCENTRATION", Quantity_PhysicalQuantity::Quantity_CONCENTRATION)
	.value("Quantity_MOLARCONCENTRATION", Quantity_PhysicalQuantity::Quantity_MOLARCONCENTRATION)
	.value("Quantity_MOLARITY", Quantity_PhysicalQuantity::Quantity_MOLARITY)
	.value("Quantity_SOUNDINTENSITY", Quantity_PhysicalQuantity::Quantity_SOUNDINTENSITY)
	.value("Quantity_ACOUSTICINTENSITY", Quantity_PhysicalQuantity::Quantity_ACOUSTICINTENSITY)
	.value("Quantity_ACTIVITY", Quantity_PhysicalQuantity::Quantity_ACTIVITY)
	.value("Quantity_ABSORBEDDOSE", Quantity_PhysicalQuantity::Quantity_ABSORBEDDOSE)
	.value("Quantity_DOSEEQUIVALENT", Quantity_PhysicalQuantity::Quantity_DOSEEQUIVALENT)
	.export_values();


}