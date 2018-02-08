/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC (info@laughlinresearch.com)

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
#ifndef __Standard_Templates_Header__
#define __Standard_Templates_Header__

#include <pyOCCT_Common.hpp>

#include <Standard_Assert.hxx>

// C:\Miniconda\envs\occt\Library\include\opencascade\Standard_Assert.hxx
template <bool condition>
void bind_Standard_Static_Assert(py::object &mod, std::string const &name) {

	// C:\Miniconda\envs\occt\Library\include\opencascade\Standard_Assert.hxx
	py::class_<Standard_Static_Assert<condition>, std::unique_ptr<Standard_Static_Assert<condition>, Deleter<Standard_Static_Assert<condition>>>> cls(mod, name.c_str(), "Static assert -- empty default template");
	cls.def(py::init<>());

};

#endif