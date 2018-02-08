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
#ifndef __Prs3d_Templates_Header__
#define __Prs3d_Templates_Header__

#include <pyOCCT_Common.hpp>

#include <Standard_Handle.hxx>
#include <Prs3d_Presentation.hxx>
#include <Prs3d_Drawer.hxx>
#include <Standard_TypeDef.hxx>
#include <Prs3d_Point.hxx>

// C:\Miniconda\envs\occt\Library\include\opencascade\Prs3d_Point.hxx
template <typename AnyPoint, typename PointTool>
void bind_Prs3d_Point(py::object &mod, std::string const &name) {

	// C:\Miniconda\envs\occt\Library\include\opencascade\Prs3d_Point.hxx
	py::class_<Prs3d_Point<AnyPoint, PointTool>, std::unique_ptr<Prs3d_Point<AnyPoint, PointTool>, Deleter<Prs3d_Point<AnyPoint, PointTool>>>> cls(mod, name.c_str(), "None");
	cls.def(py::init<>());
	cls.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const AnyPoint &, const opencascade::handle<Prs3d_Drawer> &)) &Prs3d_Point<AnyPoint, PointTool>::Add, "None", py::arg("thePresentation"), py::arg("thePoint"), py::arg("theDrawer"));
	cls.def_static("Match_", (Standard_Boolean (*)(const AnyPoint &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &Prs3d_Point<AnyPoint, PointTool>::Match, "None", py::arg("thePoint"), py::arg("theX"), py::arg("theY"), py::arg("theZ"), py::arg("theDistance"));

};

#endif