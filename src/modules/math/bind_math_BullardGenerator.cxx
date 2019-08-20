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
#include <math_BullardGenerator.hxx>

void bind_math_BullardGenerator(py::module &mod){

py::class_<math_BullardGenerator, std::unique_ptr<math_BullardGenerator>> cls_math_BullardGenerator(mod, "math_BullardGenerator", "Fast random number generator (the algorithm proposed by Ian C. Bullard).");

// Constructors
cls_math_BullardGenerator.def(py::init<>());
cls_math_BullardGenerator.def(py::init<unsigned int>(), py::arg("theSeed"));

// Fields

// Methods
cls_math_BullardGenerator.def("SetSeed", [](math_BullardGenerator &self) -> void { return self.SetSeed(); });
cls_math_BullardGenerator.def("SetSeed", (void (math_BullardGenerator::*)(unsigned int)) &math_BullardGenerator::SetSeed, "Setup new seed / reset defaults.", py::arg("theSeed"));
cls_math_BullardGenerator.def("NextInt", (unsigned int (math_BullardGenerator::*)()) &math_BullardGenerator::NextInt, "Generates new 64-bit integer value.");
cls_math_BullardGenerator.def("NextReal", (Standard_Real (math_BullardGenerator::*)()) &math_BullardGenerator::NextReal, "Generates new floating-point value.");

// Enums

}