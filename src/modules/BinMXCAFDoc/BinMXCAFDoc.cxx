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

void bind_BinMXCAFDoc(py::module &);
void bind_BinMXCAFDoc_AreaDriver(py::module &);
void bind_BinMXCAFDoc_AssemblyItemRefDriver(py::module &);
void bind_BinMXCAFDoc_CentroidDriver(py::module &);
void bind_BinMXCAFDoc_ClippingPlaneToolDriver(py::module &);
void bind_BinMXCAFDoc_ColorDriver(py::module &);
void bind_BinMXCAFDoc_ColorToolDriver(py::module &);
void bind_BinMXCAFDoc_DatumDriver(py::module &);
void bind_BinMXCAFDoc_DimensionDriver(py::module &);
void bind_BinMXCAFDoc_DimTolDriver(py::module &);
void bind_BinMXCAFDoc_DimTolToolDriver(py::module &);
void bind_BinMXCAFDoc_DocumentToolDriver(py::module &);
void bind_BinMXCAFDoc_GeomToleranceDriver(py::module &);
void bind_BinMXCAFDoc_GraphNodeDriver(py::module &);
void bind_BinMXCAFDoc_LayerToolDriver(py::module &);
void bind_BinMXCAFDoc_LocationDriver(py::module &);
void bind_BinMXCAFDoc_MaterialDriver(py::module &);
void bind_BinMXCAFDoc_MaterialToolDriver(py::module &);
void bind_BinMXCAFDoc_NoteDriver(py::module &);
void bind_BinMXCAFDoc_NoteCommentDriver(py::module &);
void bind_BinMXCAFDoc_NoteBalloonDriver(py::module &);
void bind_BinMXCAFDoc_NoteBinDataDriver(py::module &);
void bind_BinMXCAFDoc_NotesToolDriver(py::module &);
void bind_BinMXCAFDoc_ShapeToolDriver(py::module &);
void bind_BinMXCAFDoc_ViewDriver(py::module &);
void bind_BinMXCAFDoc_ViewToolDriver(py::module &);
void bind_BinMXCAFDoc_VolumeDriver(py::module &);

PYBIND11_MODULE(BinMXCAFDoc, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.BinMDF");
py::module::import("OCCT.Message");
py::module::import("OCCT.TDF");
py::module::import("OCCT.BinObjMgt");
py::module::import("OCCT.BinTools");
py::module::import("OCCT.TopLoc");

bind_BinMXCAFDoc(mod);
bind_BinMXCAFDoc_AreaDriver(mod);
bind_BinMXCAFDoc_AssemblyItemRefDriver(mod);
bind_BinMXCAFDoc_CentroidDriver(mod);
bind_BinMXCAFDoc_ClippingPlaneToolDriver(mod);
bind_BinMXCAFDoc_ColorDriver(mod);
bind_BinMXCAFDoc_ColorToolDriver(mod);
bind_BinMXCAFDoc_DatumDriver(mod);
bind_BinMXCAFDoc_DimensionDriver(mod);
bind_BinMXCAFDoc_DimTolDriver(mod);
bind_BinMXCAFDoc_DimTolToolDriver(mod);
bind_BinMXCAFDoc_DocumentToolDriver(mod);
bind_BinMXCAFDoc_GeomToleranceDriver(mod);
bind_BinMXCAFDoc_GraphNodeDriver(mod);
bind_BinMXCAFDoc_LayerToolDriver(mod);
bind_BinMXCAFDoc_LocationDriver(mod);
bind_BinMXCAFDoc_MaterialDriver(mod);
bind_BinMXCAFDoc_MaterialToolDriver(mod);
bind_BinMXCAFDoc_NoteDriver(mod);
bind_BinMXCAFDoc_NoteCommentDriver(mod);
bind_BinMXCAFDoc_NoteBalloonDriver(mod);
bind_BinMXCAFDoc_NoteBinDataDriver(mod);
bind_BinMXCAFDoc_NotesToolDriver(mod);
bind_BinMXCAFDoc_ShapeToolDriver(mod);
bind_BinMXCAFDoc_ViewDriver(mod);
bind_BinMXCAFDoc_ViewToolDriver(mod);
bind_BinMXCAFDoc_VolumeDriver(mod);

}
