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
#include <math_MultipleVarFunction.hxx>
#include <math_Vector.hxx>
#include <Standard_TypeDef.hxx>
#include <math_PSOParticlesPool.hxx>
#include <math_PSO.hxx>

void bind_math_PSO(py::module &mod){

py::class_<math_PSO, std::unique_ptr<math_PSO>> cls_math_PSO(mod, "math_PSO", "In this class implemented variation of Particle Swarm Optimization (PSO) method. A. Ismael F. Vaz, L. N. Vicente 'A particle swarm pattern search method for bound constrained global optimization'");

// Constructors
cls_math_PSO.def(py::init<math_MultipleVarFunction *, const math_Vector &, const math_Vector &, const math_Vector &>(), py::arg("theFunc"), py::arg("theLowBorder"), py::arg("theUppBorder"), py::arg("theSteps"));
cls_math_PSO.def(py::init<math_MultipleVarFunction *, const math_Vector &, const math_Vector &, const math_Vector &, const Standard_Integer>(), py::arg("theFunc"), py::arg("theLowBorder"), py::arg("theUppBorder"), py::arg("theSteps"), py::arg("theNbParticles"));
cls_math_PSO.def(py::init<math_MultipleVarFunction *, const math_Vector &, const math_Vector &, const math_Vector &, const Standard_Integer, const Standard_Integer>(), py::arg("theFunc"), py::arg("theLowBorder"), py::arg("theUppBorder"), py::arg("theSteps"), py::arg("theNbParticles"), py::arg("theNbIter"));

// Fields

// Methods
cls_math_PSO.def("Perform", [](math_PSO &self, const math_Vector & theSteps, Standard_Real & theValue, math_Vector & theOutPnt, const Standard_Integer theNbIter){ self.Perform(theSteps, theValue, theOutPnt, theNbIter); return theValue; }, "Perform computations, particles array is constructed inside of this function.", py::arg("theSteps"), py::arg("theValue"), py::arg("theOutPnt"), py::arg("theNbIter"));
cls_math_PSO.def("Perform", [](math_PSO &self, math_PSOParticlesPool & theParticles, Standard_Integer theNbParticles, Standard_Real & theValue, math_Vector & theOutPnt, const Standard_Integer theNbIter){ self.Perform(theParticles, theNbParticles, theValue, theOutPnt, theNbIter); return theValue; }, "Perform computations with given particles array.", py::arg("theParticles"), py::arg("theNbParticles"), py::arg("theValue"), py::arg("theOutPnt"), py::arg("theNbIter"));

// Enums

}