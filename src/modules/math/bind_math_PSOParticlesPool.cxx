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
#include <NCollection_Array1.hxx>

void bind_math_PSOParticlesPool(py::module &mod){

py::class_<math_PSOParticlesPool, std::unique_ptr<math_PSOParticlesPool>> cls_math_PSOParticlesPool(mod, "math_PSOParticlesPool", "None");

// Constructors
cls_math_PSOParticlesPool.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theParticlesCount"), py::arg("theDimensionCount"));

// Fields

// Methods
cls_math_PSOParticlesPool.def("GetParticle", (PSO_Particle * (math_PSOParticlesPool::*)(const Standard_Integer)) &math_PSOParticlesPool::GetParticle, "None", py::arg("theIdx"));
cls_math_PSOParticlesPool.def("GetBestParticle", (PSO_Particle * (math_PSOParticlesPool::*)()) &math_PSOParticlesPool::GetBestParticle, "None");
cls_math_PSOParticlesPool.def("GetWorstParticle", (PSO_Particle * (math_PSOParticlesPool::*)()) &math_PSOParticlesPool::GetWorstParticle, "None");

// Enums

}