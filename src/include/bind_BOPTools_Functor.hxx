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
#ifndef __BOPTools_Functor__
#define __BOPTools_Functor__

#include <pyOCCT_Common.hxx>
#include <BOPTools_Parallel.hxx>
#include <Standard_TypeDef.hxx>

template <typename TypeSolver, typename TypeSolverVector>
void bind_BOPTools_Functor(py::module &mod, std::string const &name, py::module_local const &local){

py::class_<BOPTools_Functor<TypeSolver, TypeSolverVector>, std::unique_ptr<BOPTools_Functor<TypeSolver, TypeSolverVector>>> cls_BOPTools_Functor(mod, name.c_str(), "None", local);

// Constructors
cls_BOPTools_Functor.def(py::init<TypeSolverVector &>(), py::arg("theSolverVec"));

// Fields

// Methods
cls_BOPTools_Functor.def("__call__", (void (BOPTools_Functor<TypeSolver, TypeSolverVector>::*)(const Standard_Integer) const) &BOPTools_Functor<TypeSolver, TypeSolverVector>::operator(), py::is_operator(), "Defines functor interface.", py::arg("theIndex"));

// Enums

}

#endif