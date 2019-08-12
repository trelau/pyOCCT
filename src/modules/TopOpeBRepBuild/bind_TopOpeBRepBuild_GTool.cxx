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
#include <Standard.hxx>
#include <TopOpeBRepBuild_GTopo.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <Standard_OStream.hxx>
#include <TopOpeBRepBuild_GTool.hxx>

void bind_TopOpeBRepBuild_GTool(py::module &mod){

py::class_<TopOpeBRepBuild_GTool, std::unique_ptr<TopOpeBRepBuild_GTool, Deleter<TopOpeBRepBuild_GTool>>> cls_TopOpeBRepBuild_GTool(mod, "TopOpeBRepBuild_GTool", "None");

// Constructors

// Fields

// Methods
// cls_TopOpeBRepBuild_GTool.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepBuild_GTool::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_GTool.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepBuild_GTool::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_GTool.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepBuild_GTool::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_GTool.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepBuild_GTool::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_GTool.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepBuild_GTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepBuild_GTool.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepBuild_GTool::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepBuild_GTool.def_static("GFusUnsh_", (TopOpeBRepBuild_GTopo (*)(const TopAbs_ShapeEnum, const TopAbs_ShapeEnum)) &TopOpeBRepBuild_GTool::GFusUnsh, "None", py::arg("s1"), py::arg("s2"));
cls_TopOpeBRepBuild_GTool.def_static("GFusSame_", (TopOpeBRepBuild_GTopo (*)(const TopAbs_ShapeEnum, const TopAbs_ShapeEnum)) &TopOpeBRepBuild_GTool::GFusSame, "None", py::arg("s1"), py::arg("s2"));
cls_TopOpeBRepBuild_GTool.def_static("GFusDiff_", (TopOpeBRepBuild_GTopo (*)(const TopAbs_ShapeEnum, const TopAbs_ShapeEnum)) &TopOpeBRepBuild_GTool::GFusDiff, "None", py::arg("s1"), py::arg("s2"));
cls_TopOpeBRepBuild_GTool.def_static("GCutUnsh_", (TopOpeBRepBuild_GTopo (*)(const TopAbs_ShapeEnum, const TopAbs_ShapeEnum)) &TopOpeBRepBuild_GTool::GCutUnsh, "None", py::arg("s1"), py::arg("s2"));
cls_TopOpeBRepBuild_GTool.def_static("GCutSame_", (TopOpeBRepBuild_GTopo (*)(const TopAbs_ShapeEnum, const TopAbs_ShapeEnum)) &TopOpeBRepBuild_GTool::GCutSame, "None", py::arg("s1"), py::arg("s2"));
cls_TopOpeBRepBuild_GTool.def_static("GCutDiff_", (TopOpeBRepBuild_GTopo (*)(const TopAbs_ShapeEnum, const TopAbs_ShapeEnum)) &TopOpeBRepBuild_GTool::GCutDiff, "None", py::arg("s1"), py::arg("s2"));
cls_TopOpeBRepBuild_GTool.def_static("GComUnsh_", (TopOpeBRepBuild_GTopo (*)(const TopAbs_ShapeEnum, const TopAbs_ShapeEnum)) &TopOpeBRepBuild_GTool::GComUnsh, "None", py::arg("s1"), py::arg("s2"));
cls_TopOpeBRepBuild_GTool.def_static("GComSame_", (TopOpeBRepBuild_GTopo (*)(const TopAbs_ShapeEnum, const TopAbs_ShapeEnum)) &TopOpeBRepBuild_GTool::GComSame, "None", py::arg("s1"), py::arg("s2"));
cls_TopOpeBRepBuild_GTool.def_static("GComDiff_", (TopOpeBRepBuild_GTopo (*)(const TopAbs_ShapeEnum, const TopAbs_ShapeEnum)) &TopOpeBRepBuild_GTool::GComDiff, "None", py::arg("s1"), py::arg("s2"));
cls_TopOpeBRepBuild_GTool.def_static("Dump_", (void (*)(Standard_OStream &)) &TopOpeBRepBuild_GTool::Dump, "None", py::arg("OS"));

// Enums

}