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
#include <Standard_TypeDef.hxx>
#include <math_PSOParticlesPool.hxx>

void bind_PSO_Particle(py::module &mod){

py::class_<PSO_Particle, std::unique_ptr<PSO_Particle>> cls_PSO_Particle(mod, "PSO_Particle", "Describes particle pool for using in PSO algorithm. Indexes: 0 <= aDimidx <= myDimensionCount - 1");

// Constructors
cls_PSO_Particle.def(py::init<>());

// Fields
cls_PSO_Particle.def_readwrite("Position", &PSO_Particle::Position, "None");
cls_PSO_Particle.def_readwrite("Velocity", &PSO_Particle::Velocity, "None");
cls_PSO_Particle.def_readwrite("BestPosition", &PSO_Particle::BestPosition, "None");
cls_PSO_Particle.def_readwrite("Distance", &PSO_Particle::Distance, "None");
cls_PSO_Particle.def_readwrite("BestDistance", &PSO_Particle::BestDistance, "None");

// Methods
cls_PSO_Particle.def("__lt__", (bool (PSO_Particle::*)(const PSO_Particle &) const) &PSO_Particle::operator<, py::is_operator(), "Compares the particles according to their distances.", py::arg("thePnt"));

// Enums

}