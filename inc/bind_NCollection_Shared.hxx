
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
#ifndef __bind_NCollection_Shared__
#define __bind_NCollection_Shared__

#include <pyOCCT_Common.hxx>

#include <Standard_Transient.hxx>
#include <Standard_Type.hxx>
#include <Standard_TypeDef.hxx>
#include <NCollection_Shared.hxx>

template <class T, typename = typename opencascade::std::enable_if<! opencascade::std::is_base_of<Standard_Transient, T>::value>::type>
void bind_NCollection_Shared(py::module &mod, std::string const &name, py::module_local const &local) {
    py::class_<NCollection_Shared<T>> cls(mod, name.c_str(), "None", local);

    // Constructors
    cls.def(py::init<>());
    //cls.def(py::init<const T1 &>(), py::arg("arg1"));
    //cls.def(py::init<T1 &>(), py::arg("arg1"));
    //cls.def(py::init<const T1 &, const T2 &>(), py::arg("arg1"));

}

#endif
