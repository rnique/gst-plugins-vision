/* GStreamer
 * Copyright (C) <1999> Erik Walthinsen <omega@cse.ogi.edu>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */


#ifndef __GST_FREEIMAGEENC_H__
#define __GST_FREEIMAGEENC_H__

#include <gst/gst.h>
#include <FreeImage.h>

G_BEGIN_DECLS

#define GST_FREEIMAGEENC(obj) \
  ((GstFreeImageEnc *) obj)
#define GST_FREEIMAGEENC_CLASS(klass) \
  ((GstFreeImageEncClass *) klass)
#define GST_FREEIMAGEENC_GET_CLASS(obj) \
  ((GstFreeImageEncClass *) g_type_class_peek (G_TYPE_FROM_INSTANCE (obj)))


typedef struct _GstFreeImageEnc GstFreeImageEnc;
typedef struct _GstFreeImageEncClass GstFreeImageEncClass;

struct _GstFreeImageEnc
{
  GstElement element;

  GstPad *sinkpad, *srcpad;

  gboolean need_newsegment;
  
  /* Pull range */
  long offset;


  guint64 in_timestamp;
  guint64 in_duration;

  gboolean framed;

  gint ret;

  FIBITMAP *dib;

  gboolean setup;

  gint fps_n;
  gint fps_d;

  gboolean image_ready;

  FreeImageIO fiio;
  guint64 length;
};

struct _GstFreeImageEncClass
{
  GstElementClass parent_class;

  FREE_IMAGE_FORMAT fif;
};

gboolean gst_freeimageenc_register_plugins (GstPlugin * plugin);

G_END_DECLS

#endif /* __GST_FREEIMAGEENC_H__ */
