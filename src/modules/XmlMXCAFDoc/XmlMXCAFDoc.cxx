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

void bind_XmlMXCAFDoc(py::module &);
void bind_XmlMXCAFDoc_AreaDriver(py::module &);
void bind_XmlMXCAFDoc_AssemblyItemRefDriver(py::module &);
void bind_XmlMXCAFDoc_CentroidDriver(py::module &);
void bind_XmlMXCAFDoc_ClippingPlaneToolDriver(py::module &);
void bind_XmlMXCAFDoc_ColorDriver(py::module &);
void bind_XmlMXCAFDoc_ColorToolDriver(py::module &);
void bind_XmlMXCAFDoc_DatumDriver(py::module &);
void bind_XmlMXCAFDoc_DimTolDriver(py::module &);
void bind_XmlMXCAFDoc_DimTolToolDriver(py::module &);
void bind_XmlMXCAFDoc_DocumentToolDriver(py::module &);
void bind_XmlMXCAFDoc_GraphNodeDriver(py::module &);
void bind_XmlMXCAFDoc_LayerToolDriver(py::module &);
void bind_XmlMXCAFDoc_LocationDriver(py::module &);
void bind_XmlMXCAFDoc_MaterialDriver(py::module &);
void bind_XmlMXCAFDoc_MaterialToolDriver(py::module &);
void bind_XmlMXCAFDoc_NoteDriver(py::module &);
void bind_XmlMXCAFDoc_NoteCommentDriver(py::module &);
void bind_XmlMXCAFDoc_NoteBalloonDriver(py::module &);
void bind_XmlMXCAFDoc_NoteBinDataDriver(py::module &);
void bind_XmlMXCAFDoc_NotesToolDriver(py::module &);
void bind_XmlMXCAFDoc_ShapeToolDriver(py::module &);
void bind_XmlMXCAFDoc_ViewToolDriver(py::module &);
void bind_XmlMXCAFDoc_VolumeDriver(py::module &);

PYBIND11_MODULE(XmlMXCAFDoc, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.XmlMDF");
py::module::import("OCCT.Message");
py::module::import("OCCT.TDF");
py::module::import("OCCT.XmlObjMgt");
py::module::import("OCCT.TopTools");
py::module::import("OCCT.TopLoc");

bind_XmlMXCAFDoc(mod);
bind_XmlMXCAFDoc_AreaDriver(mod);
bind_XmlMXCAFDoc_AssemblyItemRefDriver(mod);
bind_XmlMXCAFDoc_CentroidDriver(mod);
bind_XmlMXCAFDoc_ClippingPlaneToolDriver(mod);
bind_XmlMXCAFDoc_ColorDriver(mod);
bind_XmlMXCAFDoc_ColorToolDriver(mod);
bind_XmlMXCAFDoc_DatumDriver(mod);
bind_XmlMXCAFDoc_DimTolDriver(mod);
bind_XmlMXCAFDoc_DimTolToolDriver(mod);
bind_XmlMXCAFDoc_DocumentToolDriver(mod);
bind_XmlMXCAFDoc_GraphNodeDriver(mod);
bind_XmlMXCAFDoc_LayerToolDriver(mod);
bind_XmlMXCAFDoc_LocationDriver(mod);
bind_XmlMXCAFDoc_MaterialDriver(mod);
bind_XmlMXCAFDoc_MaterialToolDriver(mod);
bind_XmlMXCAFDoc_NoteDriver(mod);
bind_XmlMXCAFDoc_NoteCommentDriver(mod);
bind_XmlMXCAFDoc_NoteBalloonDriver(mod);
bind_XmlMXCAFDoc_NoteBinDataDriver(mod);
bind_XmlMXCAFDoc_NotesToolDriver(mod);
bind_XmlMXCAFDoc_ShapeToolDriver(mod);
bind_XmlMXCAFDoc_ViewToolDriver(mod);
bind_XmlMXCAFDoc_VolumeDriver(mod);

}
