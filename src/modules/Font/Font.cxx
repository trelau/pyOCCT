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

void bind_Font_FontAspect(py::module &);
void bind_IsEqual(py::module &);
void bind_Font_Rect(py::module &);
void bind_FT_Face(py::module &);
void bind_FT_Vector(py::module &);
void bind_Font_FTFont(py::module &);
void bind_Font_TextFormatter(py::module &);
void bind_Font_BRepFont(py::module &);
void bind_Font_BRepTextBuilder(py::module &);
void bind_Font_SystemFont(py::module &);
void bind_Font_NListOfSystemFont(py::module &);
void bind_Font_FontMgr(py::module &);
void bind_FT_Library(py::module &);
void bind_Font_FTLibrary(py::module &);

PYBIND11_MODULE(Font, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.Image");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.Geom2d");
py::module::import("OCCT.GeomAbs");
py::module::import("OCCT.Geom");
py::module::import("OCCT.Adaptor3d");
py::module::import("OCCT.Geom2dAdaptor");
py::module::import("OCCT.Geom2dConvert");
py::module::import("OCCT.TColgp");
py::module::import("OCCT.BRep");
py::module::import("OCCT.ShapeFix");
py::module::import("OCCT.gp");
py::module::import("OCCT.TCollection");
py::module::import("OCCT.TColStd");

bind_Font_FontAspect(mod);
bind_IsEqual(mod);
bind_Font_Rect(mod);
bind_FT_Face(mod);
bind_FT_Vector(mod);
bind_Font_FTFont(mod);
bind_Font_TextFormatter(mod);
bind_Font_BRepFont(mod);
bind_Font_BRepTextBuilder(mod);
bind_Font_SystemFont(mod);
bind_Font_NListOfSystemFont(mod);
bind_Font_FontMgr(mod);
bind_FT_Library(mod);
bind_Font_FTLibrary(mod);

}
