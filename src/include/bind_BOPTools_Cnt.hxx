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
#ifndef __BOPTools_Cnt__
#define __BOPTools_Cnt__

#include <pyOCCT_Common.hxx>
#include <Standard_TypeDef.hxx>
#include <BOPTools_Parallel.hxx>

template <typename TypeFunctor, typename TypeSolverVector>
void bind_BOPTools_Cnt(py::module &mod, std::string const &name, py::module_local const &local){

py::class_<BOPTools_Cnt<TypeFunctor, TypeSolverVector>, std::unique_ptr<BOPTools_Cnt<TypeFunctor, TypeSolverVector>>> cls_BOPTools_Cnt(mod, name.c_str(), "None", local);

// Constructors

// Fields

// Methods
cls_BOPTools_Cnt.def_static("Perform_", (void (*)(const Standard_Boolean, TypeSolverVector &)) &BOPTools_Cnt<TypeFunctor, TypeSolverVector>::Perform, "None", py::arg("isRunParallel"), py::arg("theSolverVector"));

// Enums

}

#endif