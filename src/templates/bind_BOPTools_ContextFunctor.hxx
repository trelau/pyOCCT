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
#pragma once

#include <pyOCCT_Common.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_ThreadId.hxx>
#include <NCollection_DataMap.hxx>
#include <BOPTools_Parallel.hxx>
#include <Standard_Mutex.hxx>

template <typename TypeSolver, typename TypeSolverVector, typename TypeContext, typename TN>
void bind_BOPTools_ContextFunctor(py::module &mod, std::string const &name, py::module_local const &local){

py::class_<BOPTools_ContextFunctor<TypeSolver, TypeSolverVector, TypeContext, TN>> cls_BOPTools_ContextFunctor(mod, name.c_str(), "None", local);

// Constructors
cls_BOPTools_ContextFunctor.def(py::init<TypeSolverVector &>(), py::arg("theVector"));

// Methods
cls_BOPTools_ContextFunctor.def("SetContext", (void (BOPTools_ContextFunctor<TypeSolver, TypeSolverVector, TypeContext, TN>::*)(TypeContext &)) &BOPTools_ContextFunctor<TypeSolver, TypeSolverVector, TypeContext, TN>::SetContext, "Binds main thread context", py::arg("theContext"));
cls_BOPTools_ContextFunctor.def("GetThreadContext", (TypeContext & (BOPTools_ContextFunctor<TypeSolver, TypeSolverVector, TypeContext, TN>::*)() const) &BOPTools_ContextFunctor<TypeSolver, TypeSolverVector, TypeContext, TN>::GetThreadContext, "Returns current thread context");
cls_BOPTools_ContextFunctor.def("__call__", (void (BOPTools_ContextFunctor<TypeSolver, TypeSolverVector, TypeContext, TN>::*)(const Standard_Integer) const) &BOPTools_ContextFunctor<TypeSolver, TypeSolverVector, TypeContext, TN>::operator(), py::is_operator(), "Defines functor interface", py::arg("theIndex"));

}
