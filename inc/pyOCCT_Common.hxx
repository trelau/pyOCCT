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

#ifndef __pyOCCT_Common_Header__
#define __pyOCCT_Common_Header__

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/stl_bind.h>

#include <Standard_Handle.hxx>

namespace py = pybind11;

// Use opencascade::handle as holder type for Standard_Transient types
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);

// Call guards
struct ImportGraphic3d{
	ImportGraphic3d() { py::module::import("OCCT.Graphic3d"); }
};

struct ImportLDOM{
	ImportLDOM() { py::module::import("OCCT.LDOM"); }
};

struct ImportSelect3D{
	ImportSelect3D() { py::module::import("OCCT.Select3D"); }
};

struct ImportStepShape{
	ImportStepShape() { py::module::import("OCCT.StepShape"); }
};

#endif
